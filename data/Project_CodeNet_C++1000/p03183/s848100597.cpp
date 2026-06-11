#include<bits/stdc++.h>
#define F first
#define S second
#define node pair<pair<ll,ll>,ll>
using namespace std;
typedef long long ll;
ll read(){
	ll a=0,b=getchar(),c=1;
	while(!isdigit(b))c=b=='-'?-1:1,b=getchar();
	while(isdigit(b))a=a*10+b-'0',b=getchar();
	return a*c;
}
node a[1005];
ll n,dp[20005];
bool cmp(node x,node y){
	return x.F.F+x.F.S>y.F.F+y.F.S;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)
		a[i].F.F=read(),a[i].F.S=read(),a[i].S=read();
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
		for(int j=a[i].F.F;j<=a[i].F.F+a[i].F.S;j++)
			dp[j-a[i].F.F]=max(dp[j-a[i].F.F],dp[j]+a[i].S);
	printf("%lld",dp[0]);
	return 0;
}