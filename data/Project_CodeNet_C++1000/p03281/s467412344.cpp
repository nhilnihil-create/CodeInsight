#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int f(int n) {
	int ret = 0;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			if (i * i == n) ret++;
			else ret += 2;
		}
	}
	return ret;
}

int main() {
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i += 2) {
		if (f(i) == 8) ans++;
	}
	cout << ans << endl;
	return 0;
}