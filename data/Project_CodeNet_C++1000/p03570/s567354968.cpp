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

	string s; cin >> s;
	ll n = s.size();

	vector<int> tbl(1 << 26, -2);
	tbl[0] = -1;

	ll alp = 0;
	vl dp(n + 1, TEN(10));
	dp[0] = 0;
	REP(i, n) {
		alp ^= 1 << (s[i] - 'a');
		if (__builtin_popcountll(alp) == 0) {
			dp[i + 1] = 1;
		} else {
			REP(j, 26) {
				ll c = 1 << j;
				if (c & alp == 0) continue;
				if(tbl[alp ^ c] != -2) MINC(dp[i + 1], 1 + dp[tbl[alp ^ c] + 1]);
			}
		}
		if (tbl[alp] == -2 || dp[tbl[alp] + 1] > dp[i + 1]) tbl[alp] = i;
	}
	//REP(i, n) cout << dp[i] << endl;
	//cout << endl;
	//REP(i, 26) cout << tbl[i] << endl;
	cout << dp[n] << endl;

	return 0;
}
