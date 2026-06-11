#include <bits/stdc++.h>
using namespace std;

const int N = (int) 2e5 + 5;
const long long INF = (long long) 1e18;

int n;
int a[N];
long long s[N];

long long sum(int i, int j) {
	return s[j] - s[i - 1];
}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	int l = 1, r = 3;
	long long res = INF;
	for (int i = 2; i <= n - 2; i++) {
		while (l + 1 < i && abs(sum(1, l) - sum(l + 1, i)) > abs(sum(1, l + 1) - sum(l + 2, i))) l++;
		r = max(r, i + 1);
		while (r + 1 < n && abs(sum(i + 1, r) - sum(r + 1, n)) > abs(sum(i + 1, r + 1) - sum(r + 2, n))) r++;
		long long mi = min({sum(1, l), sum(l + 1, i), sum(i + 1, r), sum(r + 1, n)});
		long long ma = max({sum(1, l), sum(l + 1, i), sum(i + 1, r), sum(r + 1, n)});
		res = min(res, ma - mi);
	}
	cout << res;
	return 0;
}