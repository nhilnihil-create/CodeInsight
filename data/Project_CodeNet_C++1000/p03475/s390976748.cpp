#define rep(i, n) for(ll i = 0; i < n; i++)
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	int n;
	cin >> n;
	vector<int> c(n-1), s(n-1), f(n-1);
	rep(i,n-1) cin >> c[i] >> s[i] >> f[i];
	for (int i=0;i<n-1;i++) {
		int t = 0;
		for (int j=i;j<n-1;j++) {
			if (t <= s[j]) t = s[j] + c[j];
			else {
				int r = t % f[j];
				if (r==0) t = t + c[j];
				else t = t + f[j] - r + c[j];
			}
		}
		cout << t << endl;
	}
	cout << 0 << endl;
	return 0;
}
