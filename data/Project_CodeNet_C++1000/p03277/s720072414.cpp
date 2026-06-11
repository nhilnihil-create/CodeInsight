#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define x first
#define y second
using namespace std;
using ll  = long long;
#define int ll

const int N = 2e5 + 100;

int fen[N];
void clear() {
	fill_n(fen, N, 0);
}
void add(int i) {
	for (; i < N; i |= i + 1) {
		++fen[i];
	}
}
int sum(int i) {
	int s = 0;
	for (; i >= 0; i = (i & (i + 1)) - 1) {
		s += fen[i];
	}
	return s;
}

int n, a[N];

int check(int x) {
	int p = 1e5, ans = 0;
	clear();
	add(p);
	for (int i = 0; i < n; ++i) {
		if (a[i] < x) {
			++p;
		} else {
			--p;
		}
		ans += sum(p - 1);
		add(p);
	}
	return ans;
}

signed main() {
#ifdef LC
    assert(freopen("input.txt", "r", stdin));
#endif
    ios::sync_with_stdio(0), cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int need = n * (n + 1) / 4;
	int lef = 0, rig = 1e9 + 2;
	while (rig - lef > 1) {
		int mid = (lef + rig) / 2;
		if (check(mid) <= need) {
			lef = mid;
		} else {
			rig = mid;
		}
	}
	cout << lef << "\n";
    return 0;
}
