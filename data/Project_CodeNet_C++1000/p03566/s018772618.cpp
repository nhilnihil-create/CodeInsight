// practice with Dukkha
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 100, S = 20000;

int tt[N], vv[N], oo[S], pp[S], qq[S];

int main() {
	int n; cin >> n;
	int s = 0;
	for (int i = 0; i < n; i++) {
		int t; cin >> t;
		s += tt[i] = t;
	}
	for (int i = 0; i < n; i++) {
		int v; cin >> v;
		vv[i] = v;
	}
	for (int h = 0; h < s; h++) {
		oo[h] = s;
		pp[h] = h;
		qq[h] = s - 1 - h;
	}
	for (int l = 0, i = 0; i < n; i++) {
		int t = tt[i], v = vv[i];
		int r = l + t;
		for (int h = l; h < r; h++)
			oo[h] = min(oo[h], v);
		for (int h = r; h < s; h++)
			pp[h] = min(pp[h], v + h - r);
		for (int h = 0; h < l; h++)
			qq[h] = min(qq[h], v + l - 1 - h);
		l = r;
	}
	double ans = 0;
	for (int h = 0; h < s; h++) {
		int o = oo[h], p = pp[h], q = qq[h];
		if (o <= p && o <= q)
			ans += o;
		else
			ans += p == q ? p + 0.25 : min(p, q) + 0.5;
	}
	printf("%f\n", ans);
	return 0;
}
