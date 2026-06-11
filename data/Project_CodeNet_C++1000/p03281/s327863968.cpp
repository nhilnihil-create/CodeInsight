#ifdef __GNUC__
#pragma GCC target("avx2")
#pragma GCC optimize ("O20")
#pragma GCC optimize ("tree-vectorize")
#pragma GCC optimize("unroll-loops")
#define iss std::cin
#endif
#include "bits/stdc++.h"
#define rep(i, times) for(ll i = 0; i < (times); ++i)
using ll = int; using namespace std;

#ifndef __GNUC__
string text =
R"X(105)X";
stringstream iss{text};
#endif

ll cnt;
int main( ) {
	cin.tie(0);	ios::sync_with_stdio(0);
	ll N; iss >> N;
	for (ll i = 3; i <= N; i += 2) {
		ll cnt8{0};
		for (ll j = 1; j <= i; ++j) {
			if (i % j == 0) ++cnt8;
		}
		if (cnt8 == 8) ++cnt;
	}
	cout << cnt << "\n";
}
