#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]){

	string S;
	cin >> S;

	char A[3] = {0};
	A[0] = S[0]; A[1] = S[1];
	int a = atoi(A);

	char B[3] = {0};
	B[0] = S[2]; B[1] = S[3];
	int b = atoi(B);

	if(a >= 1 && a <=12 && b >= 1 && b <= 12){
		printf("AMBIGUOUS\n");
	}
	else if((a == 0 || a > 12) && b >= 1 && b <= 12){
		printf("YYMM\n");
	}
	else if(a >= 1 && a <= 12 && (b == 0 || b > 12)){
		printf("MMYY\n");
	}
	else{
		printf("NA\n");
	}
	return 0;
}