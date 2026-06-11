#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
const int maxn = 5e3 + 55;
ll n, a, b, dp[maxn][maxn], p[maxn];
ll cost(int i, int j) {
	if(p[i]==j-1) return 0;
	return p[i] < j-1 ? a : b;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> a >> b;
	for(int t, i = 1; i <= n; i++) {
		cin >> t;
		p[t] = i;
	}
	memset(dp, 0x3f, sizeof dp);
	for(int i = 0; i <= n+1; i++)
		dp[0][i] = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n+1; j++) {
			dp[i][j] = min(dp[i][j-1], dp[i-1][j] + cost(i, j));
		}
	}
	cout << dp[n][n+1];
}
