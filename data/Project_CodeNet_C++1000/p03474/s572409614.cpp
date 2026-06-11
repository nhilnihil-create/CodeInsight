#include <stdio.h>

int main() {
	int A, B;
	scanf("%d %d", &A, &B);
	int N;
	N = A+B+1;
	
	char S[N];
	scanf("%s", &S);
	
	int y = 0;
	for(int i = 0; i < N; i++){
		if(i!=A){
		if(S[i] >= '0' && S[i] <= '9'){
			y+=1;
		}
		}else if (S[i] == '-'){
			y+=1;
		}
	}
	
	if(y == A + B + 1){
		printf("Yes");
	}else{
		printf("No");
	}
	
	
	return 0;
}