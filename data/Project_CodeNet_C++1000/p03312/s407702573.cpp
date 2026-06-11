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
#include <bitset>

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
//constexpr ll MOD = 998244353;
using std::cout;
using std::endl;
using std::cin;
using std::sort;
using std::pair;
using std::string;
using std::stack;
using std::queue;
using std::vector;
using std::list;
using std::map;
using std::unordered_map;
using std::multimap;
using std::unordered_multimap;
using std::set;
using std::unordered_set;
using std::multiset;
using std::bitset;


// ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
// ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll pow(ll a, ll b) { ll ans = 1; while (b > 0) { if (b % 2 == 1) { ans *= a; ans %= MOD; }b /= 2; a *= a; a %= MOD; }return ans; }
// ll comb(ll a, ll b) { static constexpr ll size = 1e6; static VL fac(size); static VL finv(size); static VL inv(size); static ll n = 0; if (n > a) { return fac[a] * (finv[b] * finv[a - b] % MOD) % MOD; }fac[0] = fac[1] = 1; finv[0] = finv[1] = 1; inv[1] = 1; FOR(i, 2, a + 1) { inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD; fac[i] = fac[i - 1] * (ll)i%MOD; finv[i] = finv[i - 1] * inv[i] % MOD; }n = a + 1; return comb(a, b); }
// multiset<ll> prime_decomposition(ll n) { ll i = 2; multiset<ll> table{}; while (i * i <= n) { while (n % i == 0) { n /= i;	table.emplace(i); }++i; }if (n > 1) { table.emplace(n); return table; }return table; }
//-- bit -- REP(i, (1 << n)) {REP(j, n) {cout << (1 & (i >> j));}cout << endl;}

//==============================================================================================

int main() {
	ll n;
	cin >> n;
	VL v(n);
	REP(i, n) { cin >> v[i]; }

	VL sumList;
	sumList.reserve(n + 1);
	sumList.emplace_back(0);
	REPC(x, v) {
		sumList.emplace_back(*--sumList.end() + x);
	}

	ll min = 1e10;
	FOR(i, 2, n - 1) {
		// cout << 0 << " " << i - 1 << " : " << i << " " << n - 1 << endl;
		ll m1, M1, m2, M2;
		{
			if (i == 2) {
				m1 = std::min(v[1], v[0]);
				M1 = std::max(v[1], v[0]);
			} else {
				double mid = (double)sumList[i] / 2.0;
				auto p = std::lower_bound(ALL(sumList), mid);
				ll it = p - sumList.begin() - 1;
				if (it == 0) { ++it; }
				if (it == i) { --it; }
				{
					ll l = sumList[it + 1];
					ll r = sumList[i] - l;
					m1 = std::min(l, r);
					M1 = std::max(l, r);
				}
				{
					--it;
					ll l = sumList[it + 1];
					ll r = sumList[i] - l;
					m1 = std::max(m1, std::min(l, r));
					M1 = std::min(M1, std::max(l, r));
				}
			}
		}
		{
			if (i == n - 2) {
				m2 = std::min(v[n - 1], v[n - 2]);
				M2 = std::max(v[n - 1], v[n - 2]);
			} else {
				double mid = (double)(sumList[n] - sumList[i]) / 2.0;

				auto p = std::lower_bound(ALL(sumList), mid + sumList[i]);
				ll it = p - sumList.begin() - 1;
				if (it == i) { ++it; }
				if (it == n - 1) { --it; }
				{
					ll l = sumList[it + 1] - sumList[i];
					ll r = sumList[n] - sumList[it + 1];
					m2 = std::min(l, r);
					M2 = std::max(l, r);
				}
				{
					--it;
					ll l = sumList[it + 1] - sumList[i];
					ll r = sumList[n] - sumList[it + 1];
					m2 = std::max(m2, std::min(l, r));
					M2 = std::min(M2, std::max(l, r));
				}

			}
			// cout << m1 << " " << M1 << " " << m2 << " " << M2 << endl;
		}
		VL tmpV = { m1,m2,M1,M2 };
		ll tmp = *std::max_element(ALL(tmpV)) - *std::min_element(ALL(tmpV));
		// cout << tmp << endl;
		min = std::min(min, tmp);

	}
	cout << min << endl;
}
