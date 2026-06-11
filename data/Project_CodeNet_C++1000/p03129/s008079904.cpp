#include <bits/stdc++.h>
using namespace std;

signed main() {
	int n, k;
	cin >> n >> k;
	n = n / 2 + n % 2;
	if (n >= k) cout << "YES" << endl;
	else cout << "NO" << endl;
}

