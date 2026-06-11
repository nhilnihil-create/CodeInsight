#include<iostream>
#include<string>
#include<algorithm>    
#include<cmath>
#include<map>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<stack>
#include<queue>
#include<tuple>
#include<cassert>
#include<set>
#define int long long
using namespace std;
const int INF = 1000000000000;
const int mod = 1000000007;
int test[345678];
signed main() {
	int n, mi = 0, ma = 0, ans = 0; cin >> n;
	for (int h = 0; h < n; h++) {
		cin >> test[h];
	}
	reverse(test, test + n);
	for (int h = 0; h < n; h++) {
		if (h == 0) {
			if (test[h] != 2) { cout << -1 << endl; return 0; }
			mi = test[h]; ma = test[h] * 2 - 1;
		}
		else {
			mi += test[h] - 1;
			mi = mi / test[h] * test[h];
			ma = ma / test[h] * test[h] + test[h] - 1;
		}
		if (mi > ma) { cout << -1 << endl; return 0; }
	}
	cout << mi << ' ' << ma << endl;
	return 0;
}