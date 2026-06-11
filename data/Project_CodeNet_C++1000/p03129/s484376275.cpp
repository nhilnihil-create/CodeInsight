#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	int n, k; cin >> n >> k;
	string ans = "NO";
	if (n % 2 == 0) {
		if (k <= n / 2) ans = "YES";
	}
	else {
		if (k <= n / 2 + 1) ans = "YES";
	}
	cout << ans << endl;
	return 0;
}