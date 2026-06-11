#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define ALL(v) (v).begin(),(v).end()

typedef pair<int, int> P;

const int MOD = (int) 1e9 + 7;

template<class T>
bool chmax(T &a, const T &b) {
	if (a < b) {
		a = b;
		return 1;
	}
	return 0;
}

template<class T>
bool chmin(T &a, const T &b) {
	if (b < a) {
		a = b;
		return 1;
	}
	return 0;
}

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	ll N, C;
	cin >> N >> C;
	
	vector<ll> x(N + 2), v(N + 2);
	for (ll i = 1; i <= N; i++) {
		cin >> x[i] >> v[i];
	}
	x[0] = 0;
	x[N + 1] = C;
	
	ll cal = 0;
	vector<vector<ll>> dp(2, vector<ll>(100010, 0));
	
	for (ll i = 1; i <= N; i++) {
		cal -= x[i] - x[i - 1];
		cal += v[i];
		dp[0][i] = max(dp[0][i - 1], cal);
		// ここでそれまでのカロリーの最大値をメモ
	}
	
	cal = 0;
	for (ll i = N; i >= 1; i--) {
		cal -= x[i + 1] - x[i];
		cal += v[i];
		dp[1][i] = max(dp[1][i + 1], cal);
	}
	
	ll maxcal = 0;
	for (ll i = 0; i <= N; i++) {
		// 時計回り
		cal = dp[0][i] + dp[1][i + 1] - x[i];
		maxcal = max(maxcal, cal);
		
		// 反時計回り
		cal = dp[0][i] + dp[1][i + 1] - C + x[i + 1];
		maxcal = max(maxcal, cal);
	}
	
	cout << maxcal << endl;
	
	return 0;
}