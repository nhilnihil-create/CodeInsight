#include <cstdio>
int n,k;
int main(){
	scanf("%d %d",&n,&k);
	if((1<<n)<=k || (n == 1 && k == 1))return printf("-1"),0;
	if(n == 1&&k == 0)return printf("0 0 1 1"),0;
	for(int i=0;i<(1<<n);++i)
		if(i != k)printf("%d ",i);
	printf("%d ",k);
	for(int i=(1<<n)-1;~i;--i)
		if(i != k)printf("%d ",i);
	printf("%d ",k);
	return 0;
}