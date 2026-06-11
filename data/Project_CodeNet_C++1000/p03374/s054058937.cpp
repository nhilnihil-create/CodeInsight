#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1e9
#define LINF 1e18

typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<int, P> Pi;

typedef pair<P, P> PP;

const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };

template <class T> void chmin(T& a, const T& b) { a = min(a, b); }
template <class T> void chmax(T& a, const T& b) { a = max(a, b); }

int N, C;
int x[100001], c[100001];
int Rsum[100001], Lsum[100001];
int dp[2][100001];

signed main() {
	cin >> N >> C;
	for(int i = 0; i < N; ++i) {
		cin >> x[i] >> c[i];
	}
	int res = 0;
	for(int i = 0; i < N; ++i) {
		Rsum[i + 1] = Rsum[i] + c[i];
		Lsum[i + 1] = Lsum[i] + c[N - 1 - i];
	}
	for(int i = 1; i < N + 1; ++i) {
		chmax(res, Rsum[i] - x[i - 1]);
		chmax(res, Lsum[i] - (C - x[N - i]));
	}
	for(int i = 1; i < N + 1; ++i) {
		dp[0][i] = max(dp[0][i - 1], Lsum[i] - (C - x[N - i]));
		dp[1][i] = max(dp[1][i - 1], Rsum[i] - x[i - 1]);
	}
	for(int i = 1; i < N + 1; ++i) {
		chmax(res, Rsum[i] - x[i - 1] * 2 + dp[0][N - i]);
		chmax(res, Lsum[i] - (C - x[N - i]) * 2 + dp[1][N - i]);
	}
	cout << res << endl;
	return 0;
}
