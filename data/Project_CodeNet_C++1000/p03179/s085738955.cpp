#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9+7;
const int MAX_N = 3006;
int n;
string s;
ll dp[MAX_N][MAX_N], pfx[MAX_N][MAX_N];

void solve()
{
	dp[1][1] = 1;
	for(int i=2;i<=n;i++){
	    for(int x=1;x<=i;x++) pfx[i-1][x]=(pfx[i-1][x-1]+dp[i-1][x])%MOD;
		if(s[i-2]=='<'){
			for(int j=1;j<=i;j++){
			    // 1..j-1
				dp[i][j] = pfx[i-1][j-1];
			}
		}
		else{
			for(int j=1;j<=i;j++){
			    // > prev value j..i-1
				dp[i][j] = (pfx[i-1][i-1]-pfx[i-1][j-1]+MOD)%MOD;
			}
		}
	}
	ll ans = 0;
	for(int x=1;x<=n;++x) (ans+=dp[n][x])%=MOD;
	cout << ans << '\n';
}

int main()
{
	cin >> n >> s;
	solve();
	return 0;
}