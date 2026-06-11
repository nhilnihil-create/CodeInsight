#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>

using namespace std;
using lint = int64_t;
using P = pair<int, int>;
using D = pair<double, double>;

#define rep(i, n) for (lint i = 0; i < (n); ++i)
#define rep1(i, n) for (lint i = 1; i < (n); ++i)
#define repn(i, a, b) for(lint i = (a); i < (b); ++i)
#define Rep(i, n) for (lint i = (n); i >= 0; --i)
#define All(vec) vec.begin(), vec.end()
#define cend printf("\n")

//constexpr lint mod = 998'244'353LL;
constexpr lint mod = 1000'000'007LL;
constexpr lint inf = 3LL * mod * mod;
const double Pi = 2.0 * acos(0.0);

template<class T> using prique     = priority_queue<T>;
template<class T> using prique_inv = priority_queue<T, vector<T>, greater<T>>;
template<class T, class U>inline istream& operator>>(istream& is, pair<T, U>& rhs) { return is >> rhs.first >> rhs.second; }
template<class T, class U>inline ostream& operator<<(ostream& os, const pair<T, U>& rhs) { return os << rhs.first << " " << rhs.second << "\n"; }
template<class T> void vecin(vector<T>& v) { arrin(v.begin(), v.end()); }
template<class T> void vecout(vector<T>& v) { arrout(v.begin(), v.end()); }
template<class InputIterator> void arrin(InputIterator first, InputIterator last) { for (; first != last; ++first) cin >> (*first); }
template<class InputIterator> void arrout(InputIterator first, InputIterator last) {
	for (; first != last; ++first) {
		cout << (*first) << ((first + 1) != last ? " " : "\n");
	}
}

constexpr bool pri(lint x) { for (lint i = 2; i * i <= x; ++i) if (x % i == 0) return false; return 1 < x; }

inline double dis(D a, D b) { return hypot(a.first - b.first, a.second - b.second); }

lint fact[3000000];
void fact_init(lint n) {
	if (3000000 <= n) return;
	fact[0] = fact[1] = 1;
	for (lint i = 2; i <= n; ++i) {
		fact[i] = i * fact[i - 1];
		if (mod <= fact[i]) fact[i] %= mod;
	}
}

lint modpow(lint x, lint n, lint m = mod) {
	lint res = 1;
	while (n > 0) {
		if (n & 1) {
			res *= x;
			if (m <= res) res %= m;
		}
		x *= x;
		if (m <= x) x %= m;
		n >>= 1;
	}
	return res;
}

lint intpow(lint x, lint n) {
	lint res = 1;
	while (n > 0) {
		if (n & 1) res *= x;
		x *= x;
		n >>= 1;
	}
	return res;
}

lint comb(lint n, lint r) {
	if (r == 0 || r == n) return 1;
	lint res = fact[n] * modpow(fact[n - r], mod - 2) % mod * modpow(fact[r], mod - 2) % mod;
	return res < 0 ? res + mod : res;
}

map<lint, lint> factring(lint n) {
	map<lint, lint> res;
	for (lint i = 2; i * i <= n; ++i) {
		while (n % i == 0) {
			n /= i;
			++res[i];
		}
	}
	if (n != 1) ++res[n];
	return res;
}

int n, mem, ans = 1;
int cnt[2 * 100010];
int main() {
	cin >> n;
	rep(i, n) {
		int p;
		cin >> p;
		cnt[p - 1] = i;
	}
	mem = n;
	for (int i = n - 1; i > 0; --i) {
		if (cnt[i] < cnt[i - 1]) {
			ans = max(ans, mem - i);
			mem = i;
		}
	}
	ans = max(ans, mem);
	cout << n - ans << endl;
}