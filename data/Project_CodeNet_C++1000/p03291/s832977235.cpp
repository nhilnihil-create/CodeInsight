#include "bits/stdc++.h"
using namespace std;

#define ASC(vec) vec.begin(), vec.end()    // 昇順ソート 例：sort(ASC(vec));
#define DESC(vec) vec.rbegin(), vec.rend() // 降順ソート 例：sort(DESC(vec));
#define rep(i, n) for (int i = 0; i < (n); i++)
#define Rep(i, n) for (int i = 1; i < n; i++)
#define REP(i, vec) for (auto i = vec.begin(); i != vec.end(); ++i)

const int       mod = 1000000007;
const int       inf = (1 << 21);
const long long INF = 1LL << 60;

using ii = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vd = vector<double>;
using vb = vector<bool>;
using vl = vector<ll>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vvb = vector<vector<bool>>;
using vii = vector<pair<int, int>>;
using vll = vector<pair<ll, ll>>;

template<class T>
inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T>
inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T>
inline T GCD(T a, T b) { return b ? GCD(b, a % b) : a; }
template<class T>
inline T LCM(T a, T b) { return (a + (b - 1)) / b; }
template<class T>
inline T round_int(T a, T b) {return (a + (b - 1)) / b; }

constexpr array<int, 9> dx = { 0, 1, 0, -1, -1, 1, 1, -1, 0 };
constexpr array<int, 9> dy = { 1, 0, -1, 0, 1, 1, -1, -1, 0 };

// ──────────────────────────────────────────────────────────────────

void add(ll& a, ll b) {
	a += b;
	if (a >= mod) a -= mod;
}

ll dp[210000][5];

int main() {
	string s;
	cin >> s;

	dp[0][0] = 1;

	rep(i, s.size()) {
		rep(j, 5) {
			if (s[i] == '?') add(dp[i + 1][j], dp[i][j] * 3 % mod);
			else add(dp[i + 1][j], dp[i][j]);
		}

		if (s[i] == 'A' || s[i] == '?') add(dp[i + 1][1], dp[i][0]);
		if (s[i] == 'B' || s[i] == '?') add(dp[i + 1][2], dp[i][1]);
		if (s[i] == 'C' || s[i] == '?') add(dp[i + 1][3], dp[i][2]);
	}
	cout << dp[s.size()][3] << endl;
}