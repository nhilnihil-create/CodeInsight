#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	long double n, m, d;
	cin >> n >> m >> d;
	long double ans;
	if(d == 0)
		ans = (m - 1) / n;
	else
		ans = 2 * (n - d) * (m - 1) / (n * n);
	cout << fixed << setprecision(12) << ans << "\n";
	return 0;
}
