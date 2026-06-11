#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
	int d, n;
	cin >> d >> n;
	if (d == 0) {
		if (n < 100) cout << n << endl;
		else cout << 101 << endl;
		return 0;
	}
	int ans;
	if (d == 1) {
		ans = 100;
		if (n < 100) cout << n * ans << endl;
		else cout << 10100 << endl;
	}
	else {
		ans = 10000;
		if (n < 100) cout << n * ans << endl;
		else cout << 101 * ans << endl;
	}


	return 0;
}