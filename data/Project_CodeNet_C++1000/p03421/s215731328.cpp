#include<cstdio>
#include<algorithm>
#define int long long
int n,A,B,p[300005];
signed main(){
	scanf("%lld%lld%lld",&n,&A,&B);
	if(n<A+B-1||n>A*B)return puts("-1"),0;
	int cnt=0,now=1;
	for(int i=n-A+1;i<=n;i++){
		p[++cnt]=i;
		int x=std::min(now+B-2,n-A);
		for(int j=1;now<=n-A&&j<B;j++,now++)
			p[++cnt]=x--;
	}
	for(int i=1;i<=n;i++)
		printf("%lld ",p[i]);
}