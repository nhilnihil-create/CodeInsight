#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const LL N = 1000000007;

struct node{
	LL w,s,v;
}b[1005];
bool cmp(node x,node y){
	if(x.s + x.w == y.s + y.w) return x.s < y.s;
	return x.s + x.w < y.s + y.w;
}

LL n,V;
LL dp[1005][30005] = {0};

int main(){
	scanf("%lld",&n);
	for(LL i = 1;i <= n;i ++) scanf("%lld %lld %lld",&b[i].w,&b[i].s,&b[i].v);
	sort(b + 1,b + 1 + n,cmp);
	V = b[n].s + b[n].w;
	for(LL i = 1;i <= n;i ++){
		for(LL v = 0;v <= V;v ++) dp[i][v] = max(dp[i][v],dp[i - 1][v]);
		for(LL v = 0;v <= b[i].s;v ++) dp[i][v + b[i].w] = max(dp[i][v + b[i].w],dp[i - 1][v] + b[i].v);
	}
	LL ans = 0;
	for(LL i = 0;i <= V;i ++) ans = max(ans,dp[n][i]);
	printf("%lld\n",ans);
	return 0;
}