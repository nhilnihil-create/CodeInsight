#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
	int n, x;
	cin >> n >> x;
	int rem = x;
	int a[102];
	rep(i, n) cin >> a[i];
	sort(a, a+n);
	rep(i, n) {
		if (rem < a[i]) {
			cout << i << endl;
			return 0; 
		}
		rem -= a[i];
	}
	if (rem == 0) cout << n << endl;
	else cout << n-1 << endl;
	return 0;
}