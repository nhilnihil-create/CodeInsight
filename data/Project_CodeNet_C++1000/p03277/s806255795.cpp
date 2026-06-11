//besmellah
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = 1e5 + 5;
int a[maxn], fen[2 * maxn], ps[maxn];
map <int, int> M;
vector <int> compress;

void add(int id, int val) {
	for (; id < 2 * maxn; id += id & -id)
		fen[id] += val;
}

int get(int id) {
	int ans = 0;
	for (; id; id -= id & -id)
		ans += fen[id];
	return ans;
}

int bs(int n) {
	int l = 0, r = n + 1;
	while (r > l + 1) {
		int mid = (l + r) / 2;
		for (int i = 0; i < n; i++) {
			if (a[i] <= mid) {
				ps[i + 1] = ps[i] + 1;
			}
			else
				ps[i + 1] = ps[i] - 1;
		}
		int ans = 0;
		for (int i = 0; i <= n; i++) {
			ans += get(ps[i] + n);
			add(ps[i] + n + 1, +1);
		}
		if (ans > (n * (n + 1) / 2) / 2)
			r = mid;
		else
			l = mid;
		fill(fen, fen + 2 * maxn, 0);
	}
	return l;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		compress.push_back(a[i]);
	}
	sort(compress.begin(), compress.end());
	compress.resize(unique(compress.begin(), compress.end()) - compress.begin());
	int sz = compress.size();
	for (int i = 0; i < sz; i++)
		M[compress[i]] = i;
	for (int i = 0; i < n; i++)
		a[i] = M[a[i]] + 1;
	cout << compress[bs(n)];
}
