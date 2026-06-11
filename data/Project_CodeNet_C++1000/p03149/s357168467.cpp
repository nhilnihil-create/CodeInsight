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
#include<functional>
//#include<bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;
const ll INF = 1000000000000000000;
const ll mod = 1000000007;
const ld pi = 3.141592653589793238;
//printf("%.10f\n", n);

ll gcd(ll a, ll b) {
	if (a < b)swap(a, b);
	if (a % b == 0)return b;
	return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}
ll modpow(ll x, ll y) {
	ll res = 1;
	while (y) {
		if (y % 2) { res *= x; res %= mod; }
		x = x * x % mod; y /= 2;
	}
	return res;
}

ll test[1234];
signed main() {
	ll n, x, l, q, a = 0, b = 0, c = 0, d = 0, ans = 0;
	for (int h = 0; h < 4; h++) {
		cin >> test[h];
	}
	sort(test, test + 4);
	if (test[0] == 1 && test[1] == 4 && test[2] == 7 && test[3] == 9) {
		cout << "YES" << endl;
	}
	else { cout << "NO" << endl; }
	
	return 0;
}
