#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main() {
	int n, m, ans = 0;
	cin >> n >> m;
	for (int i = 1; i*i <= m; i++) {
		if (m%i != 0) continue;
		int a, b;
		a = i;
		b = m / a;
		if ((long long)a*n <= m)
			ans = max(ans, a);
		if ((long long)b*n <= m)
			ans = max(ans, b);
	}
	cout << ans << endl;
	return 0;
}