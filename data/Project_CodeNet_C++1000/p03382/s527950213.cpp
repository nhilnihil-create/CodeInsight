#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int s = a.back();
	int g = s / 2;
	int t;
	int dif = 1 << 30;
	for (int i = 0; i < n - 1; i++) {
		if (abs(g - a[i]) <= dif) {
			dif = abs(g - a[i]);
			t = a[i];
		}
	}
	cout << s << " " << t << endl;
	return 0;	
}