#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

ll INF = 1LL << 60;

vector<vector<ll>> dp(10, vector<ll>(10));
vector<vector<pint>> G(10);

int main() {
	int H, W;
	cin >> H >> W;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			int c;
			cin >> c;
			G[i].push_back(make_pair(c, j));
		}
	}
	
	dp.assign(10, vector<ll>(10,INF));
	for (int i = 0; i < 10; i++) {
		dp[i][i] = 0;
		for (pint p : G[i]) {
			int w = p.first;
			int v = p.second;
			dp[i][v] = w;
		}
	}

	for (int k = 0; k < 10; k++) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}

	ll ans = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			int a;
			cin >> a;
			if (a == -1 || a == 1) continue;
			ans += dp[a][1];
		}
	}
	cout << ans << endl;

	return 0;
}