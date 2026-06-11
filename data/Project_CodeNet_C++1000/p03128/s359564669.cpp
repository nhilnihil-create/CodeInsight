// practice with Dukkha
#include <algorithm>
#include <iostream>

using namespace std;

int d2c[] = { 0, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

int dd[8];
int qu[9], aa[9], aa_[9];
int k_, l_;
int c_;

void update(int k, int l) {
	if (l_ > l)
		return;
	for (int h = 0; h < k; h++)
		aa[h] = dd[qu[h]];
	int m = min(l, 9);
	for (int h = k; h < m; h++)
		aa[h] = dd[c_];
	sort(aa, aa + m, greater<>());
	bool better = false;
	if (l_ < l)
		better = true;
	else
		for (int h = 0; h < l; h++)
			if (aa_[h] != aa[h]) {
				if (aa_[h] < aa[h])
					better = true;
				break;
			}
	if (better) {
		k_ = k;
		l_ = l;
		for (int h = 0; h < m; h++)
			aa_[h] = aa[h];
	}
}

void solve(int c, int n, int k) {
	while (c > c_ && dd[c] == 0)
		c--;
	if (c == c_) {
		if (n % c == 0) {
			int l = k + n / c;
			update(k, l);
		}
		return;
	}
	for (int h = 0; h < c_; h++) {
		solve(c - 1, n, k);
		if (n < c || k == 9)
			break;
		n -= c;
		qu[k++] = c;
	}
}

int main() {
	int n, m; cin >> n >> m;
	while (m--) {
		int d; cin >> d;
		int c = d2c[d];
		dd[c] = max(dd[c], d);
	}
	c_ = 2;
	while (dd[c_] == 0)
		c_++;
	solve(7, n, 0);
	m = min(l_, 9);
	for (int h = 0; h < m; h++)
		if (aa_[h] > dd[c_])
			cout << aa_[h];
	for (int h = k_; h < l_; h++)
		cout << dd[c_];
	for (int h = 0; h < m; h++)
		if (aa_[h] < dd[c_])
			cout << aa_[h];
	cout << '\n';
	return 0;
}
