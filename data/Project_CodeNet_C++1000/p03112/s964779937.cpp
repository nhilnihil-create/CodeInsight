#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, q;
	cin >> a >> b >> q;
	vector<long long> s(a), t(b);
	for (int i = 0; i < a; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < b; i++) {
		cin >> t[i];
	}
	vector<long long> ans;
	for (int i = 0, sl, sr, tl, tr, mid; i < q; i++) {
		long long x, ns, nt;
		cin >> x;
		ans.clear();
		sl = -1, sr = a;
		while (sr - sl > 1) {
			mid = (sl + sr) / 2;
			if (x > s[mid])
				sl = mid;
			else
				sr = mid;
		}
		tl = -1, tr = b;
		while (tr - tl > 1) {
			mid = (tl + tr) / 2;
			if (x > t[mid])
				tl = mid;
			else
				tr = mid;
		}
		if (sl > -1 && tl > -1)
			ans.emplace_back(max(x - s[sl], x - t[tl]));
		if (sr < a && tr < b)
			ans.emplace_back(max(s[sr] - x, t[tr] - x));

		if (sl < 0) {
			ns = s[sr] - x;
		} else if (sr > a - 1) {
			ns = x - s[sl];
		} else {
			ns = min(x - s[sl], s[sr] - x);
		}
		if (tl < 0) {
			nt = t[tr] - x;
		} else if (tr > b - 1) {
			nt = x - t[tl];
		} else {
			nt = min(x - t[tl], t[tr] - x);
		}
		ans.emplace_back(min(ns * 2 + nt, nt * 2 + ns));
		cout << *min_element(ans.begin(), ans.end()) << endl;
	}
}
