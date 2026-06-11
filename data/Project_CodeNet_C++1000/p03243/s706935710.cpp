#include"bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long

signed main() {
	int n; cin >> n;
	rep(i, 10) {
		if (n <= 111 * i) {
			cout << 111*i << endl; return 0;
		}
	}
}