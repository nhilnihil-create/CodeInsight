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
	ll n, a, cnt = 1, ans = 0; cin >> n >> a;
	for (int h = 1; h < a - n; h++) {
		ans += h;
	}
	cout << ans - n << endl;
	cin >> n; return 0;
}