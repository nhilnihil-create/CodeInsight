#include<iostream>
#include<string>
#include<algorithm>    
#include<cmath>
#include<map>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<queue>
#define int long long
#define mod (int)(1000000007)
using namespace std;
int test[213456], aa[213456];

signed main() {
	int n, a = 1234567890, ans = 0; cin >> n;
	for (int h = 0; h < n; h++) {
		cin >> test[h];
	}
	sort(test, test + n);
	for (int h = 0; h < n - 1; h++) {
		if (abs((double)test[n - 1] / 2 - test[h]) < a) {
			a = abs((double)test[n - 1] / 2 - test[h]);
			ans = test[h];
		}
	}
	cout << test[n - 1] << ' ' << ans << endl;
}