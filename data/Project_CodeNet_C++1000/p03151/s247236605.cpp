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
int test[345678], kari[345678], cost[345678];
signed main() {
	int n, a, b, c = 0, cnt = 0, ans = 0; cin >> n;
	int z = 0;
	for (int h = 0; h < n; h++) {
		cin >> a; cnt += a; test[h] = a;
	}
	for (int h = 0; h < n; h++) {
		cin >> b; cnt -= b; kari[h] = b;
	}
	if (cnt < 0) { cout << -1 << endl; return 0; }
	for (int h = 0; h < n; h++) {
		if (test[h] < kari[h]) { ans += kari[h] - test[h]; z++; }
		if (test[h] > kari[h]) { cost[c] = test[h] - kari[h]; c++; }
	}
	sort(cost, cost + c);
	if (ans == 0) { cout << 0 << endl; return 0; }
	for (int h = c - 1; h >= 0; h--) {
		ans -= cost[h]; z++;
		if (ans < 1) { cout << z << endl; return 0; }
	}
	return 0;
}