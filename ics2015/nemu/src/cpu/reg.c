#include "nemu.h"
#include <stdlib.h>
#include <time.h>

CPU_state cpu;

const char *regsl[] = {"eax", "ecx", "edx", "ebx", "esp", "ebp", "esi", "edi"};
const char *regsw[] = {"ax", "cx", "dx", "bx", "sp", "bp", "si", "di"};
const char *regsb[] = {"al", "cl", "dl", "bl", "ah", "ch", "dh", "bh"};

void reg_test() {
	srand(time(0));
	uint32_t sample[8];
	uint32_t eip_sample = rand();
	cpu.eip = eip_sample;

	int i;
	for(i = R_EAX; i <= R_EDI; i ++) {
		sample[i] = rand();
		reg_l(i) = sample[i];
		reg_w(i) = sample[i] & 0xffff;
		assert(reg_w(i) == (sample[i] & 0xffff));
	}

	reg_b(R_AL) = (sample[R_EAX] & 0xff);
	reg_b(R_AH) = ((sample[R_EAX] >> 8) & 0xff);

	assert(reg_b(R_AL) == (sample[R_EAX] & 0xff));
	assert(reg_b(R_AH) == ((sample[R_EAX] >> 8) & 0xff));

	reg_b(R_BL) = (sample[R_EBX] & 0xff);

	assert(reg_b(R_BL) == (sample[R_EBX] & 0xff));

	reg_b(R_BH) = ((sample[R_EBX] >> 8) & 0xff);

	assert(reg_b(R_BH) == ((sample[R_EBX] >> 8) & 0xff));

	reg_b(R_CL) = (sample[R_ECX] & 0xff);

	assert(reg_b(R_CL) == (sample[R_ECX] & 0xff));

	reg_b(R_CH) = ((sample[R_ECX] >> 8) & 0xff);

	assert(reg_b(R_CH) == ((sample[R_ECX] >> 8) & 0xff));

	reg_b(R_DL) = (sample[R_EDX] & 0xff);

	assert(reg_b(R_DL) == (sample[R_EDX] & 0xff));

	reg_b(R_DH) = ((sample[R_EDX] >> 8) & 0xff);

	assert(reg_b(R_DH) == ((sample[R_EDX] >> 8) & 0xff));
	
	cpu.eax = sample[R_EAX];
	cpu.ecx = sample[R_ECX];
	cpu.edx = sample[R_EDX];
    cpu.ebx = sample[R_EBX];
	cpu.esp = sample[R_ESP];
	cpu.ebp = sample[R_EBP];
	cpu.esi = sample[R_ESI];
	cpu.edi = sample[R_EDI];

	assert(sample[R_EAX] == cpu.eax);
	assert(sample[R_ECX] == cpu.ecx);
	assert(sample[R_EDX] == cpu.edx);
	assert(sample[R_EBX] == cpu.ebx);
	assert(sample[R_ESP] == cpu.esp);
	assert(sample[R_EBP] == cpu.ebp);
	assert(sample[R_ESI] == cpu.esi);
	assert(sample[R_EDI] == cpu.edi);

	eip_sample = cpu.eip;
	assert(eip_sample == cpu.eip);
}
