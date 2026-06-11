#include<bits/stdc++.h>
using namespace std;
const int INF = 100000;
int dp[100005];
int f(int n){
	//cout<<n<<'\n';
	int&ret = dp[n];
	if(~ret) return ret;
	ret = INF;
	for(int i=6; i<=n; i*=6) ret = min(ret,f(n-i)+1);
	for(int i=9; i<=n; i*=9) ret = min(ret,f(n-i)+1);
	ret = min(ret,f(n-1)+1);
	return ret;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(dp,-1,sizeof(dp));
	dp[1] = 1;
	dp[0] = 0;
	for(int i=6; i<=INF; i*=6) dp[i] = 1;
	for(int i=9; i<=INF; i*=9) dp[i] = 1;
	int n;
	cin>>n;
	cout<<f(n);
}