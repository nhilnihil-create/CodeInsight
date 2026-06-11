/*
数据不清空，爆零两行泪。
多测不读完，爆零两行泪。
边界不特判，爆零两行泪。
贪心不证明，爆零两行泪。
D P 顺序错，爆零两行泪。
大小少等号，爆零两行泪。
变量不统一，爆零两行泪。
越界不判断，爆零两行泪。
调试不注释，爆零两行泪。
溢出不 l l，爆零两行泪。
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1000,W_I=10000,S_I=10000;
int n;
struct object{int w,s,v;}obj[N+1];
bool operator<(object x,object y){return y.s-x.w>x.s-y.w;}
int dp[N+1][W_I+S_I+1];
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>obj[i].w>>obj[i].s>>obj[i].v;
	sort(obj+1,obj+n+1);
	for(int i=1;i<=n;i++)for(int j=0;j<=W_I+S_I;j++){
		dp[i][j]=dp[i-1][j];
		if(j>=obj[i].w)dp[i][j]=max(dp[i][j],dp[i-1][min(j-obj[i].w,obj[i].s)]+obj[i].v);
	}
	cout<<dp[n][W_I+S_I];
	return 0;
}