#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

int n, a, b, c, d, e;

signed main() {
	cin >> n >> a >> b >> c >> d >> e;
	int mn = min({a, b, c, d, e});
	cout << 5 + (n - 1) / mn << endl;
	return 0;
}