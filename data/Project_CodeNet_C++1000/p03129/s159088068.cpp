#include <stdio.h>
int main(){
	int N=0;
	int K=0;
	scanf("%d %d", &N, &K);
	if(K<=100&&1<=N){
		bool ac=(N+1)/2>=K;
		if(ac){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}