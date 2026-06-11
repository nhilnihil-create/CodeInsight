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
	ll n;
	cin >> n;
	vector<ll> vs(n);
	rep(i, n) cin >> vs[i];
	unordered_map<ll, ll> m;
	rep(i, n) {
		m[vs[i]] = i + 1;
	}
	ll maxLen = 0;
	ll len = 0;
	ll prev = 0;
	for (int i = 1; i <= n; i++) {
		if (m[i] > prev) {
			len++;
		}
		else {
			len = 1;
		}
		maxLen = max(maxLen, len);
		prev = m[i];
	}
	cout << (n - maxLen) << endl;
	return 0;
}
