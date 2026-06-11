#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main() {
	int a, b, c, x, cnt = 0;
	cin >> a >> b >> c >> x;
	a++, b++, c++;
	rep(i, a) {
		rep(j, b) {
			rep(k, c) {
				if (500 * i + 100 * j + 50 * k == x) cnt++;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}