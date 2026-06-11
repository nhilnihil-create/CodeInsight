#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

signed main() {
	int n;
	cin >> n;
	int x=0, y = 0;
	vector<int> v(n);
	rep(i, n) cin >> v[i];
	rep(i, n) {
		int c; cin >> c;
		if (c < v[i]){
			x += v[i];
			y += c;
		}
	}
	cout << x - y << endl;
}
