#include"bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long
typedef pair<int, int> P;

signed main() {
	int a, b, k; cin >> a >> b >> k;
	rep(i, k) {
		if (i & 1) {
			if (b & 1)b--;
			a += b / 2;
			b /= 2;
		}
		else {
			if (a & 1)a--;
			b += a / 2;
			a /= 2;
		}
	}
	cout << a << ' ' << b << endl;
}