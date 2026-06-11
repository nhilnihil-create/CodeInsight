#include <stdio.h>
#include <string.h>

int main(){
	int N, K, X=1;
	scanf("%d %d", &N, &K);
	while (N>0){
		if(X<=K){
			X*=2;
		}
		else{
			X+=K;
		}
		N--;
	}
	printf ("%d", X);
return 0;
}
