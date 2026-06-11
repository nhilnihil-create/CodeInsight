#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
#define endl '\n'
#define fi first
#define se second
#define pi pair<ll,ll>
#define pii pair<ll,pi>
#define pb push_back
#define mk make_pair
const int inf = 1e9;
const int nax = 207;
int n, m;
vector<vector<int>>a(nax, vector<int>(nax));
vector<vector<int>>dp(11, vector<int>(11));
void floydwarshall() {
	for (int k = 0; k < 10; k++) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (dp[i][j] > dp[i][k] + dp[k][j]) {
					dp[i][j] = dp[i][k] + dp[k][j];
				}
			}
		}
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> dp[i][j];
		}
	}
	floydwarshall();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == -1)continue;
			ans += dp[a[i][j]][1];
		}
	}
	cout << ans << endl;
}