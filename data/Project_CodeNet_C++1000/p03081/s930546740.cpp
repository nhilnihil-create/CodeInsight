#include <bits/stdc++.h>
using namespace std;
//#define cerr if (false) cerr
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define dbv(v) cerr << #v << "="; for (auto _x : v) cerr << _x << ", "; cerr << endl
#define dba(a, n) cerr << #a << "="; for (int _i = 0; _i < (n); ++_i) cerr << a[_i] << ", "; cerr << endl
typedef long long ll;
typedef long double ld;
char str[200005];
int main() {
	int n, q;
	scanf("%d%d%s", &n, &q, str);
	vector<char> t(q), d(q);
	for (int i = 0; i < q; ++i) {
		scanf(" %c %c", &t[i], &d[i]);
	}
	auto simulate = [&](int p) {
		for (int i = 0; i < q; ++i) {
			if (p == 0 || p == n + 1) continue;
			if (str[p - 1] != t[i]) continue;
			if (d[i] == 'L') --p;
			else ++p;
		}
		return p;
	};
	int lo = 0, hi = n + 1;
	while (lo < hi) {
		int m = (lo + hi) >> 1;
		if (simulate(m) == n + 1) hi = m;
		else lo = m + 1;
	}
	int r = lo;
	lo = 0;
	hi = n + 1;
	while (lo < hi) {
		int m = (lo + hi + 1) >> 1;
		if (simulate(m) == 0) lo = m;
		else hi = m - 1;
	}
	int l = lo;
	int ans = n - (n + 1 - r) - l;
	printf("%d\n", ans);
}
