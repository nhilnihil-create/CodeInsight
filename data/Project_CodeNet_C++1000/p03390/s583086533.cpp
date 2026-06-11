#include<stdio.h>
#include<math.h>
#include<stdlib.h>
long long int solve(long long int a, long long int b){
	long double c=sqrtl(a*b-1);
	long long int seisuu=c;
	if(a==b){
		return seisuu*2;
	}else if(seisuu*(seisuu+1)>=a*b){
		return seisuu*2-2;
		printf("zensha\n");
	}else{
		return seisuu*2-1;		
		printf("kousha\n");
	}
} 
int main(){
	int q=0;
	long long int query[2][100];
	scanf("%d\n",&q);
	for(int i=0;i<q;i++){
		query[0][i]=0;
		query[1][i]=0;
		scanf("%d %d\n",&query[0][i],&query[1][i]);
	}
	for(int i=0;i<q;i++){
		printf("%lld\n", solve(query[0][i], query[1][i]));
	}
/*	long long int a=101;
	long double b=sqrtl(a);
	long long int c=b;
	printf("%llf\n",b);
	printf("%lld\n",c);*/
}

	