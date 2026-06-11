#include<cstdio>
#include<algorithm>
using namespace std;
int N,A,B,que[300005];
int main(void){
	int i,bl,l,r,t,now=0;
	scanf("%d%d%d",&N,&A,&B);
	if(A+B>N+1||1ll*A*B<N){
		puts("-1");
		return 0;
	}
	r=N,l=r-A+1;
	for(;now<A;)que[++now]=l+now-1;t=1;
	r=l-1,l=max(1,r-A+1);
	while(r&&t+r+1-min(A,r-l+1)>=B){
		for(i=1;i<=A&&l+i-1<=r;++i)que[++now]=l+i-1;++t,r=l-1,l=max(1,r-A+1);
	}
	l=1,r=B-t,bl=r+1;
	for(i=r;i;--i)que[++now]=i;
	for(i=1;now<=N;++i)que[++now]=bl+i-1;
	for(i=1;i<=N;++i)printf("%d ",que[i]);
	return 0;
}
