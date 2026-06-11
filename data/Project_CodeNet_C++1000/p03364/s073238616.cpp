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
	vector<string> grid(n);
	rep(i, n) cin >> grid[i];

	ll sum = 0;
	rep(i, n) {
		auto ss = i;
		bool ok = true;
		rep(j, n) {
			repi(k,j+1,n) {
				if (grid[j][(k + ss) % n] != grid[k][(j + ss) % n]) {
					ok = false;
					break;
				}
			}
			if (!ok) break;
		}
		if (ok) sum++;
	}
	cout << sum * n << endl;

	return 0;
}
