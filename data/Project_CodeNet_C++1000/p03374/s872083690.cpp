#include<bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;
using ll = long long;
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
const int INF = 1e9;
int main() {	
	ll N, C;
	cin >> N >> C;
	vector<ll>x(N + 2), v(N + 2);
	for (int i = 1; i <= N; i++) {
		cin >> x[i] >> v[i];
	}
	x[0] = 0;
	x[N + 1] = C;
	ll cal = 0;
	vector<vector<ll>>dp(2, vector<ll>(100010));
	for (int i = 1; i <= N; i++) {
		cal -= x[i] - x[i - 1];
		cal += v[i];
		dp[0][i] = max(dp[0][i - 1], cal);
	}
	cal = 0;
	for (int i = N; i >= 1; i--) {
		cal -= x[i + 1] - x[i];
		cal += v[i];
		dp[1][i] = max(dp[1][i + 1], cal);
	}
	ll maxcal = 0;
	for (int i = 0; i <= N; i++) {
		cal = dp[0][i] + dp[1][i + 1] - x[i];
		maxcal = max(maxcal, cal);
		cal = dp[0][i] + dp[1][i + 1] - C + x[i + 1];
		maxcal = max(maxcal, cal);
	}
	cout << maxcal << endl;
}
