#include"bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long

signed main() {
	int n; cin >> n;
	double ans = 0;
	rep(i, n) {
		double a; string s;
		cin >> a >> s;
		if (s == "JPY")ans += a;
		else ans += a * 380000;
	}
	printf("%.9lf\n", ans);
}