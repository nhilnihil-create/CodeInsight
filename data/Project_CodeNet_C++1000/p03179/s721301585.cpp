#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using ll=long long;

#define fi first
#define se second
#define pb push_back
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define MOD 1000000007

vector<vector<ll>> dp(3010, vector<ll>(3010));
int main() {
	int N;
	string s;
	cin >> N >> s;
	rep(i,N) {
		dp[0][i] = 1;
	}
	ll acc[N];
	rep(i,N) {
		if(i==0) acc[i] = dp[0][i];
		else acc[i] = dp[0][i] + acc[i-1];
	}
	for(int i=1; i<N; i++) {
		if(s[i-1] == '<') {
			rep(j,N-i) {
				dp[i][j] = (acc[N-i] - acc[j] + MOD) % MOD;
				/*for(int k=j+1; k<=N-i+1; k++) {
					dp[i][j] = (dp[i][j]+dp[i-1][k]) % MOD;
				}*/
			}
		}
		else {
			rep(j,N-i) {
				dp[i][j] = acc[j];
				/*rep(k,j+1) {
					dp[i][j] = (dp[i][j] + dp[i-1][k]) % MOD;
				}*/
			}
		}
		rep(j,N-i) {
			if(j == 0) acc[j] = dp[i][j];
			else acc[j] = (acc[j-1] + dp[i][j]) % MOD;
		}
	}
	/*rep(i,N) {
		rep(j,N) cout << setw(3) << dp[i][j];
		cout << endl;
	}*/
	ll ans = dp[N-1][0];
	cout << ans << endl;

  return 0;
}
