#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using u32 = uint32_t;
using vi = vector<int>;    using vvi = vector<vi>;
using vb = vector<bool>;   using vvb = vector<vb>;
using vl = vector<ll>;     using vvl = vector<vl>;
using vd = vector<double>; using vvd = vector<vd>;

#define MAXC(c, x) (c = max(c, x))
#define MINC(c, x) (c = min(c, x))

#define REP(i,n) for(auto i = 0 * (n), i##_len = (n); i < i##_len; ++i)
#define ALL(c) (c).begin(), (c).end()
#define FOR(i,s,n) for(ll i=s, i##_len=(ll)(n); i<i##_len; ++i)
#define TEN(x) ((ll)1e##x)
const ll mod = TEN(9) + 7;

const ll INF = 1e9;

int main() {
	#ifdef INPUT_FROM_FILE
	ifstream cin("sample.in");
	ofstream cout("sample.out");
	#endif
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(50);

	string s; ll K;
	cin >> s >> K;
	ll n = s.size();

	ll ans = -1;
	// dp[現在の位置（左）（変更可）][現在の位置（右）][変更回数]
	vector<vvl> dp(n + 1, vvl(n + 1, vl(K + 1, -1)));
	dp[0][0][0] = 0;
	REP(i, n) REP(j, n) REP(k, K + 1) {
		if (dp[i][j][k] < 0) continue;
		if (i + j + 1 == n) { // 同じ場所になったとき
			ans = max(ans, dp[i][j][k] * 2 + 1);
		} else if (i + j == n) { // すれ違ったとき
			ans = max(ans, dp[i][j][k] * 2);
		} else {
			if (s[i] == s[n - j - 1]) MAXC(dp[i + 1][j + 1][k], dp[i][j][k] + 1);
			if (k < K) MAXC(dp[i + 1][j + 1][k + 1], dp[i][j][k] + 1);
			MAXC(dp[i + 1][j][k], dp[i][j][k]);
			MAXC(dp[i][j + 1][k], dp[i][j][k]);
		}
	}
	cout << ans << endl;

	return 0;
}
