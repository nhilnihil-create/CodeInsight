#include<cstdio>
using ull = unsigned long long;
 
int main(){
	ull N, M;
	scanf("%llu %llu", &N, &M);
	if(N == 1 && M == 1){
		printf("1\n");
		return 0;
	}
	if(N == 1){
		printf("%d\n", M-2);
		return 0;
	}
	if(M == 1){
		printf("%d\n", N-2);
		return 0;
	}
	printf("%lld\n", (N - 2)*(M - 2));
	return 0;
}