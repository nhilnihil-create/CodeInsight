#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

signed main() {
	int r, d, x;
	cin >> r >> d >> x;
	int ans = 0;
	rep(i, 10) {
		x = r * x - d;
		cout << x << endl;
	}
}
