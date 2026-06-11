#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int n, d, x;
int chocolate(int a) {
	return (d - 1) / a + 1;
}
int main() {
	cin >> n >> d >> x;
	int ans = x;
	rep(i, n) {
		int a; cin >> a;
		ans += chocolate(a);
	}
	cout << ans << endl;
	return 0;
}