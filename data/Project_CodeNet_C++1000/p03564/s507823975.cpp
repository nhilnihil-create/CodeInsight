#include <stdio.h>

int main(){
	int N, K, res=1;
	scanf("%d", &N);
	scanf("%d", &K);
	int *ptrK = &K;
	for(int i=1; i<=N; i++){
		if(res*2<res+K){
			res *= 2;
		}else{
			res += K;
		}
	}
	printf("%d\n", res);
	return 0;
}