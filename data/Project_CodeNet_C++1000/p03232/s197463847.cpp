#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MX = 1e5 + 100;
const int mo = 1e9 + 7;
int inverse(int v) {
	int ans = 1;
	for(int p = mo - 2; p; p >>= 1) {
		if(p & 1) ans = ans * v % mo;
		v = v * v % mo;
	}
	return ans;
}
int inv[MX];
main () {
	int n; cin >> n;
	int p = 1;
	for(int i = 1; i <= n; i ++) {
		p = p * i % mo;
		inv[i] = (inv[i - 1] + inverse(i)) % mo;
	}
	int ans = 0;
	for(int i = 1; i <= n; i ++) {
		int in; cin >> in;
		ans = (ans + in * p % mo * (mo + inv[i] + inv[n - i + 1] - inv[1])) % mo;
	}
	cout << ans;
}