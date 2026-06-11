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
//#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll INF = 10000000000000000;
const ll mod = 1000000007;
signed main() {
	ll n, a, cnt = 0, ans = 0; cin >> n;
	vector<ll> v(n);
	for (int h = 0; h < n; h++) {
		cin >> v[h];
		if (h > 0) {
			if (v[h - 1] == v[h]) { cnt++; }
			else { cnt++; ans += cnt / 2; cnt = 0; }
		}
	}
	cnt++; ans += cnt / 2;
	cout << ans << endl;
	cin >> n; return 0;
}