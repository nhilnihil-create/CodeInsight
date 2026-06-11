#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <stack>
#include <queue>

#define FOR(i, b, e) for(ll i = (ll)(b); i < (ll)(e); ++i)
#define RFOR(i, b, e) for(ll i = (ll)(e-1); i >= (ll)(b); --i)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, 0, n)
#define REPC(x,c) for(const auto& x:(c))
#define VS vector<string>
#define VL vector<long long>
#define VI vector<int>
#define VVI vector<vector<int>>
#define VVL vector<vector<ll>>
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort(ALL(x))
#define RSORT(x) sort((x).rbegin(),(x).rend())
#define PAIR pair<ll,ll>
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

using  ll = long long;
constexpr ll MOD = 1000000007;
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
using std::list;
using std::map;
using std::unordered_map;
using std::multimap;
using std::set;
using std::unordered_set;
using std::multiset;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll pow(ll a, ll b) {
	ll ans = 1;
	while (b > 0) {
		if (b % 2 == 1) {
			ans *= a;
			ans %= MOD;
		}
		b /= 2;
		a *= a;
		a %= MOD;
	}
	return ans;
}
ll comb(ll a, ll b) {
	if (a - b < b) { return comb(a, a - b); }
	ll c = 1;
	FOR(i, a - b + 1, a + 1) {
		c *= i;
		c %= MOD;
	}
	ll k = 1;
	FOR(i, 2, b + 1) {
		k *= i;
		k %= MOD;
	}
	c *= pow(k, MOD - 2);
	return c % MOD;
}
multiset<ll> prime_decomposition(ll n) {
	ll i = 2;
	multiset<ll> table{};
	while (i * i <= n) {
		while (n % i == 0) {
			n /= i;
			table.emplace(i);
		}
		++i;
	}
	if (n > 1) {
		table.emplace(n);
		return table;
	}
	return table;
}

int main() {
	string str;
	ll x, y;
	cin >> str >> x >> y;
	list<ll> a, b;
	{
		bool flg = true;
		ll count = 0;
		REPC(c, str) {
			if (c == 'T') {
				if (flg) {
					a.emplace_back(count);
				} else {
					b.emplace_back(count);
				}
				flg = !flg;
				count = -1;
			}
			++count;
		}
		if (flg) {
			a.emplace_back(count);
		} else {
			b.emplace_back(count);
		}
	}

	{
		vector<vector<bool>> dp(a.size() + 1, vector<bool>(16002, false));
		dp[0][8000] = true;
		ll i = 1;
		REPC(x, a) {
			REP(j, 16002) {
				if (j - x >= 0 && dp[i - 1][j - x]) {
					dp[i][j] = true;
				}
				if (j + x < 16002 && dp[i - 1][j + x] && !(i == 1 && str[0] == 'F')) {
					dp[i][j] = true;
				}
			}
			++i;
		}
		if (!dp[a.size()][x + 8000]) {
			cout << "No" << endl;
			return 0;
		}
	}
	{
		vector<vector<bool>> dp(b.size() + 1, vector<bool>(16002, false));
		dp[0][8000] = true;
		ll i = 1;
		REPC(x, b) {
			REP(j, 16002) {
				if (j - x >= 0 && dp[i - 1][j - x]) {
					dp[i][j] = true;
				}
				if (j + x < 16002 && dp[i - 1][j + x]) {
					dp[i][j] = true;
				}
			}
			++i;
		}
		if (!dp[b.size()][y + 8000]) {
			cout << "No" << endl;
		} else {
			cout << "Yes" << endl;
		}
	}
}