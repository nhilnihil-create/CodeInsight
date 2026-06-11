#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
using ll = long long;
const ll mod = 1e9+7;
const int mxn = 3003;
ll dp[mxn][mxn];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N; cin>>N;
	char s[mxn];
	cin>>s;

	if(s[0]=='<') dp[0][2] = 1ll;
	else dp[0][1] = 1ll;

	for(int idx = 1; idx<N-1; idx++)
		if(s[idx]=='<')
			for(int j=2; j<=idx+2; j++) {
				dp[idx][j] = dp[idx][j-1]+dp[idx-1][j-1];
				if(dp[idx][j]>=mod) dp[idx][j]-=mod;
			}
		else 
			for(int j=idx+1; j>=1; j--) {
				dp[idx][j] = dp[idx][j+1]+dp[idx-1][j];
				if(dp[idx][j]>=mod) dp[idx][j]-=mod;
		}

	ll ans = 0ll;
	for(int i=1; i<=N; i++) {
		ans+=dp[N-2][i];
		if(ans>=mod)ans-=mod;
	}

	cout << ans << '\n';


	return 0;
}