#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <queue>
#include <climits>
#define rep(i,n) for (int i=0;i<(n);i++)

using namespace std;


int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	vector<int> c(n);
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	for (int i = 0;i < n;i++) {
		cin >> b[i];
	}
	for (int i = 0;i < n;i++) {
		cin >> c[i];
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());

	long long ans = 0;
	for (int i = 0;i < n;i++) {
		long long _a = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
		long long c_ = c.end() - upper_bound(c.begin(), c.end(), b[i]);
		ans += _a * c_;
	}


	cout << ans << endl;

	return 0;
}
