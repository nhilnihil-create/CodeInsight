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
ll gcd(ll a, ll b) {
	if (a < b)swap(a, b);
	if (a % b == 0)return b;
	return gcd(b, a % b);
}
signed main() {
	ll n = 0, k, a, mae = 0, ans = 0; cin >> n >> k;
	vector<ll> v(n);
	for (int h = 0; h < n; h++) {
		cin >> v[h];
	}
	sort(v.begin(), v.end());
	ans = abs(k - v[0]);
	for (int h = 1; h < n; h++) {
		ans = gcd(ans, v[h] - v[h - 1]);
	}
	cout << ans << endl;
	cin >> n; return 0;
}