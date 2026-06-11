#include<iostream>
#include<stdio.h>
using namespace std;

int main(void) {
	int D;
	scanf("%d", &D);
	cout << "Christmas";
	for (int i = 0; i < 25 - D; i++) {
		cout << " Eve";
	}
	cout << "\n";
	return 0;
}
