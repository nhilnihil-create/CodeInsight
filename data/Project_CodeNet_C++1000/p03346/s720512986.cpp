#include<iostream>
#include<string>
#include<algorithm>    
#include<cmath>
#include<map>
#include<vector>
#include<math.h>
#include<stdio.h>
#define int long long
using namespace std;
int test[213456];
signed main() {
	int n, a, ans = 0; cin >> n;
	for (int h = 0; h < n; h++) {
		cin >> a; test[a] = test[a - 1] + 1;
	}
	for (int h = 0; h <= n; h++) {
		ans = max(ans, test[h]);
	}
	cout << n - ans << endl;
}