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

ll k;
vector<ll> as;

struct BSearch {
	ll solveLower(ll left, ll right) {
		while (right - left > 1) {
			ll middle = left + right;
			middle /= 2;
			ll r = middle;
			rep(i, k) {
				r = r / as[i] * as[i];
			}
			if (r >= 2) {
				right = middle;
			}
			else {
				left = middle;
			}
		}
		return right;
	}
	ll solveUpper(ll left, ll right) {
		while (right - left > 1) {
			ll middle = left + right;
			middle /= 2;
			ll r = middle;
			rep(i, k) {
				r = r / as[i] * as[i];
			}
			if (r > 2) {
				right = middle;
			}
			else {
				left = middle;
			}
		}
		return left;
	}
};

int main(void)
{
	cin >> k;
	as.resize(k);
	rep(i, k) cin >> as[i];
	BSearch b;
	auto down = b.solveLower(0, 1e15);
	auto up = b.solveUpper(0, 1e15);
	if (down > up) {
		cout << -1 << endl;
	}
	else {
		cout << down << " " << up << endl;
	}
	return 0;
}
