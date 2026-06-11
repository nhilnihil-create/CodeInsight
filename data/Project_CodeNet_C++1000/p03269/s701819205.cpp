
// Problem : D - All Your Paths are Different Lengths
// Contest : AtCoder Regular Contest 102
// URL : https://atcoder.jp/contests/arc102/tasks/arc102_b
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define cerr if(1)cerr
#define size(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define temptts template <class T, class... Ts>

const int N = 1e6 + 1, mod = 1e9 + 7, inf = 2e9;

struct edge {
	int u, v, w;
};

int n, l;
vector<edge> v;

int main() { cin.tie(0)->sync_with_stdio(0);
	cin >> l;
	l--;
	int x = __lg(l) + 1;
	n = x;
	if ((1 << x) - 1 == l) {
		n++;
	}
	for (int i = 2; i <= n; i++) {
		v.push_back({i - 1, i, 0});
		v.push_back({i - 1, i, 1 << (n - i)});
	}
	int cur = 0;
	if ((1 << x) - 1 != l) for (int i = x - 1; i >= 0; i--) {
		int bit = 1 << i;
		if (l & bit) {
			cur += bit;
			l -= bit;
			int j = l ? __lg(l) : 0;
			v.push_back({1, n - j, cur});
		}
	}
	cout << n << ' ' << size(v) << '\n';
	for (auto x : v) {
		cout << x.u << ' ' << x.v << ' ' << x.w << '\n';
	}
}
