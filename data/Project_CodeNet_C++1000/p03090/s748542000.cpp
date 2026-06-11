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
signed main() {
	int n, cnt = 0; cin >> n; int ng = n;
	if (ng % 2 == 0) { ng++; }
	for (int h = 1; h <= n; h++) {
		for (int i = h + 1; i <= n; i++) {
			if (h + i != ng) { cnt++; }
		}
	}
	cout << cnt << endl;
	for (int h = 1; h <= n; h++) {
		for (int i = h + 1; i <= n; i++) {
			if (h + i != ng) {
				cout << h << ' ' << i << endl;
			}
		}
	}
	return 0;
}