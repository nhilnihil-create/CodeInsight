#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int main() {
	int n, k;
	cin >> n >> k;
	int t = 1;
	int cnt = 0;
	while (t < k) {
		t *= 2;
		cnt++;
	}
	double s = 0;
	for (int i = 1; i <= n; i++) {
		if (i * t < k) t *= 2;
		double x = 1.0 / t;
		s += x;
		if (t > 1) t /= 2;
	}
	double ans = s / n;
	printf("%.20f\n", ans);
	return 0;
}