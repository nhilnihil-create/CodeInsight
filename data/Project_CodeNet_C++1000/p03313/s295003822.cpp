#include <bits/stdc++.h>
using namespace std;

int a[1 << 19], n;
pair<int, int> f[1 << 19];

inline void update(pair<int, int>& a, pair<int, int>& b) {
	int t[4];
	t[0] = a.first; t[1] = a.second; t[2] = b.first; t[3] = b.second;
	sort(t, t + 4, [&](const int& i, const int& j) {
		return ::a[i] > ::a[j];
	});
	unique(t, t + 4);
	a.first = t[0]; a.second = t[1];
}

inline int calc(int x) {
	int ans = 0;
	for(int i = n - 1; i >= 0; -- i) {
		if(~x >> i & 1) continue;
		int p = ((x >> (i + 1) << (i + 1)) | ((1 << i) - 1));
		if(ans < a[f[p].first] + a[f[p].second]) ans = a[f[p].first] + a[f[p].second];
	}
	if(ans < a[f[x].first] + a[f[x].second]) ans = a[f[x].first] + a[f[x].second];
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 0; i < (1 << n); ++ i) cin >> a[i];
	a[1 << n] = 0;
	for(int i = 0; i < (1 << n); ++ i) f[i] = make_pair(i, 1 << n);
	for(int i = 0; i < n; ++ i)
	for(int j = 0; j < (1 << n); ++ j) {
		if(~j >> i & 1) {
			update(f[j | (1 << i)], f[j]);
		}
	}
	for(int i = 1; i < (1 << n); ++ i) {
		cout << calc(i) << "\n";
	}
	return 0;
}
