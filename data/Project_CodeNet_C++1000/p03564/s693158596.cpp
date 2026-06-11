#include <stdio.h>

int main(){
	int A, B, output = 1;
	scanf("%d %d", &A, &B);
	
	for(int i = 0; i < A; i++){
		(output + B > output*2) ? output *= 2 : output += B;
	}
	
	printf("%d\n", output);
	return 0;
}