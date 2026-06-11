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
//printf("%.10f\n", n);
signed main() {
	ll n, m, a = 0, b = 0, cnt = 0, ans = INF;
	string s, t; cin >> s;
	for (int h = 2; h < s.size(); h++) {
		a = 0;
		a += (ll)(s[h - 2] - '0') * 100;
		a += (ll)(s[h - 1] - '0') * 10;
		a += (ll)(s[h] - '0');
		ans = min(ans, abs(a - 753));
	}
	cout << ans << endl;
	cin >> n; return 0;
}