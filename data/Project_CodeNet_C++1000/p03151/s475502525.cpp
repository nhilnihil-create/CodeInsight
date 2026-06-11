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
#define mod(int)(1000000007)
using namespace std;
int test[213456], sum[213456], cnt[213456];
signed main() {
	int n, k, a = 0, b = 0, ok = 0, ans = 0; cin >> n;
	for (int h = 0; h < n; h++) {
		cin >> test[h]; ok += test[h];
	}
	for (int h = 0; h < n; h++) {
		cin >> sum[h]; ok -= sum[h];
	}
	for (int h = 0; h < n; h++) {
		if (test[h] > sum[h]) { cnt[a] = test[h] - sum[h]; a++; }
		if (test[h] < sum[h]) { b += sum[h] - test[h]; ans++; }
	}
	sort(cnt, cnt + a);
	if (ok < 0) {
		cout << -1 << endl; return 0;
	}
	for (int h = a - 1; h >= 0; h--) {
		if (b > 0) { b -= cnt[h]; ans++; }
		else { break; }
	}
	cout << ans << endl;
	return 0;
}