#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include <math.h>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <deque>
#include <queue>

#define rep(i, n) for(int i = 0; i < n; ++i)
#define REP(i, m, n) for(int i = m; i < n; ++i)
#define rrep(i,n) for(int i = n; i >= 0; --i)
#define RREP(i, m, n) for(int i = n; i >= m; --i)
#define llrep(i, n) for(ll i = 0; i < n; ++i)
#define llREP(i, m, n) for(ll i = m; i < n; ++i)
#define llrrep(i,n) for(ll i = n; i >= 0; --i)
#define llRREP(i, m, n) for(ll i = n; i >= m; --i)

using ll = long long;
using ull = unsigned long long;
using pii = std::pair<int, int>;
using pll = std::pair<long long, long long>;

using namespace std;

const long long mod = 1000000007;
const long long MOD = 998244353;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	string s;
	cin >> n >> s;

	ll abc[26] = { 0 };
	rep(i, n) ++abc[s[i] - 'a'];

	ll ans = 1;
	rep(i, 26) {
		ans *= abc[i] + 1;
		ans %= mod;
	}

	cout << ans - 1 << "\n";

	return 0; 
}
