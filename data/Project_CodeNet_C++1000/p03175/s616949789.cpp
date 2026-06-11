#include <bits/stdc++.h>
using namespace std;
long long dp[100005][2], n, a, b, mod=1000000007;
vector<long long> c[100005];
void root(int cur, int par){
	vector<long long> novi;
	for (int i=0; i<c[cur].size(); i++){
		if (c[cur][i]!=par){
			novi.push_back(c[cur][i]);
			root (c[cur][i], cur);
		}
	} c[cur]=novi; return;
}
void solve(int cur){
	dp[cur][0]=dp[cur][1]=1;
	for (int i=0; i<c[cur].size(); i++) solve(c[cur][i]);
	for (int i=0; i<c[cur].size(); i++){
		dp[cur][0] = (dp[cur][0]*(dp[c[cur][i]][0] + dp[c[cur][i]][1]))%mod;
		dp[cur][1] = (dp[cur][1]*dp[c[cur][i]][0])%mod;
	} dp[cur][0]%=mod; dp[cur][1]%=mod; 
	return;
}
int main (){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i=1; i<n; i++){
		cin >> a >> b;
		c[a].push_back(b);
		c[b].push_back(a);
	} 
	root(1, 0); solve(1); 
	cout << ((dp[1][0]+dp[1][1])%mod) << endl;
return 0;
}
