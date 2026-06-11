#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <string>
#include <tuple>
#include <random>
#include <map>
#include <queue>
#include <set>
#include <complex>
#include <algorithm>
#include <cassert>
#include <iterator>
#include <numeric>
#include <cmath>
#include <stdio.h>
#include <functional>

using namespace std;
using ll = long long;
using ld = double;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll, ll>; //(x, y, dx, dy)
const ll INF = 1e17;
const ld eps = 1e-10;
const ll MOD = 1e9 + 7;

const double pi = acos(-1.0);

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N, A, B;
	cin >> N >> A >> B;
	vector<ll> p(N);
	for (int i = 0;i < N;i++) {
		cin >> p[i];
		p[i]--;
	}
	vector<ll> minimax(N, -1);
	for (int base = 0;base < N;base++) {
		for (int i = base + 1;i < N;i++) {
			if (p[i] < p[base])
				minimax[base] = max(minimax[base], p[i]);
		}
	}
	vector<vector<ll>> dp(N + 1, vector<ll>(N, INF));
	dp[0][0] = 0;
	for (int i = 0;i < N;i++) {
		ll nowmini = INF;
		for (int j = 0;j < N;j++) { // jより小さいやつは飛ばす
			if (p[i] < j)
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + B);
			else {
				if (minimax[i] >= j)
					dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + A);
				else
					dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
				nowmini = min(nowmini, dp[i][j]);
			}
		}
		dp[i + 1][p[i]] = min(dp[i + 1][p[i]], nowmini);
	}
	ll ans = INF;
	for (int i = 0;i < N;i++)
		ans = min(ans, dp[N][i]);
	cout << ans << endl;
	return 0;
}
