#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int main() {
	int n, k;
	cin >> n >> k;
	double ans = 0;
	for (int i = 1; i <= n; i++) {
		int a = i;
		double b = 1;
		while (a < k) {
			a *= 2;
			b *= 0.5;
		}
		ans += b / n;
	}
	printf("%.10f\n", ans);
	return 0;
}