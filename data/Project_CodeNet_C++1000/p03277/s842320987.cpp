#include<bits/stdc++.h>
using namespace std;
const int M = 100001;
const int N = 2e5 + 10;

int n, a[N], b[N], sum[N], tr[N];

inline void Add(int x) {
	while (x < N) tr[x]++, x += x & -x;
}

inline int Query(int x) {
	int ans = 0;
	while (x) ans += tr[x], x -= x & -x;
	return ans;
}

int check(int mid) {
	long long tot =1LL * n * (n + 1) / 2;
	tot = tot / 2 + 1;
	memset(tr, 0, sizeof(tr));
	for (int i = 1; i <= n; ++i) b[i] = (a[i] <= mid) ^ 1;
	Add(M);
	long long res = 0;
	int s1 = 0, s0 = 0;
	for (int i = 1; i <= n; ++i) {
		if (!b[i]) s0++; else s1++;
		int s = s1 - s0;
		res += Query(N - 1) - Query(s + M);
//		cout << Query(N - 1) << ' ' << Query(s + M) << endl;
		Add(s + M);
	}
//	cout << res << endl;
	return (res >= tot);
}

int main() {
	cin >> n;
	int l = 1, r = 1e9;
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), r = max(r, a[i]);
	while (l < r) {
		int mid = (l + r) >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << endl;
	return 0;
}
