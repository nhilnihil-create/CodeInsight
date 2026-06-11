#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 1005;
const ll inf = 1e16;
ll dp[2][N][8];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n, m;
	cin>>n>>m;
	for(int i = 0; i <= m; i++){
		for(int mask = 0; mask < 8; mask++){
			dp[0][i][mask] = -inf;
		}
	}
	for(int mask = 0; mask < 8; mask++){
		dp[0][0][mask] = 0;
	}
	ll x[3];
	int flg = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 3; j++){
			cin>>x[j];
		}
		for(int mask = 0; mask < 8; mask++){
			ll cost = 0;
			for(int j = 0; j < 3; j++){
				if(mask&(1<<j))cost += x[j];
				else cost -= x[j];
			}
			dp[flg^1][0][mask] = 0;
			for(int cnt = 1; cnt <= m; cnt++){
				dp[flg^1][cnt][mask] = max(dp[flg][cnt][mask], dp[flg][cnt - 1][mask] + cost);
			}
		}
		for(int cnt = 0; cnt <= m; cnt++){
			for(int mask = 0; mask < 8; mask++){
				dp[flg][cnt][mask] = -inf;
			}
		}
		flg ^= 1;
	}
	ll ans = -inf;
	for(int mask = 0; mask < 8; mask++){
		ans = max(ans, dp[flg][m][mask]);
	}
	cout<<ans<<'\n';

	return 0;
}