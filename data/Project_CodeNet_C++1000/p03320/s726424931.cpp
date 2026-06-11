#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using ii = pair<int, int>;

inline int S(ll x) { int ret = 0; while (x) ret += x % 10, x /= 10; return ret; }
inline ll pw(int b, int e) { ll ret = 1; while (e--) ret *= b; return ret; }

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	ll K, a = 2, b = 0, i = 0; cin >> K;
	while (i < K) {
		ll x = a * pw(10, b) - 1, y = (a + 1) * pw(10, b) - 1;
		if (x * S(y) <= y * S(x)) {
			cout << x << '\n';
			++i, ++a;
		}
		else a = x / pw(10, ++b) + 1;
	}
}