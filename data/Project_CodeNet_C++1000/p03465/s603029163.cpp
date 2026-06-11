#pragma once

#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;

#define rep(a,n) for(int a = 0;a < n;a++)
#define repi(a,b,n) for(int a = b;a < n;a++)

const ull mod = 1e9+7;

int main(void)
{
	ll n; cin >> n;
	vector<ll> a(n); rep(i, n) cin >> a[i];
	ll sum = 0;
	rep(i, n) sum += a[i];
	bitset<4000050> dp;
	dp[0] = 1;
	rep(i, n) {
		auto dp1 = dp;
		dp1 <<= a[i];
		dp |= dp1;
	}
	repi(i, (sum + 1) / 2, sum + 1) {
		if (dp[i]) {
			cout << i << endl;
			return 0;
		}
	}
}
