#include <stdio.h>

int main() {
	int N, K, otp = 1;
	
	scanf("%d %d", &N, &K);
	
	for(int i = 0; i < N; i++){
		(otp+K > otp*2)? (otp *= 2) : (otp += K);
	}
	
	printf("%d", otp);
	
	return 0;
}