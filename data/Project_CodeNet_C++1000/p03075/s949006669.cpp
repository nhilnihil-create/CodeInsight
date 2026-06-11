#include<iostream>
#include<stdio.h>
using namespace std;

int main(void) {
	int antennas[5];
	int k;
	for (int i = 0; i < 5; i++) {
		scanf("%d", &antennas[i]);
	}
	scanf("%d", &k);
	printf(antennas[4] - antennas[0] <= k ? "Yay!\n" : ":(\n");
	return 0;
}
