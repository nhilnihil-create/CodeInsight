#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)
using ll = long long;
constexpr ll INF = 1000000000;
using namespace std;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int a, b, c, x, y; cin >> a >> b >> c >> x >> y;

	vector<ll>ans(3);

	ans[0] = a * x + b * y;

	if (x > y) {
		ans[1] = 2 * y * c + (x - y) * a;
	}
	else {
		ans[1] = 2 * x * c + (y - x) * b;
	}

	ans[2] = max(x, y) * 2 * c;
	sort(ans.begin(), ans.end());
	cout << ans[0] << endl;
}