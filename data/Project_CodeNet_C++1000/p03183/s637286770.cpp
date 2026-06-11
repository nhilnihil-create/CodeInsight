#include<cstdio>
#include<algorithm>
#define ll long long 
struct r{
	int w,s,v;
}a[1050];
ll dp[20050],ans;
int lim,n;
bool cmp(r a,r b){return a.w+a.s<b.s+b.w;}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d%d%d",&a[i].w,&a[i].s,&a[i].v),lim=std::max(a[i].s,lim);
	std::sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++){
		for (int j=a[i].s;j>=0;j--)dp[j+a[i].w]=std::max(dp[j+a[i].w],dp[j]+a[i].v);
		for (int j=1;j<=lim;j++)dp[j]=std::max(dp[j],dp[j-1]);
	}
	for (int i=1;i<=20000;i++)ans=std::max(dp[i],ans);
	printf("%lld",ans);
}