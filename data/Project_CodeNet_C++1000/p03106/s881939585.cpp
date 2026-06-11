#ifdef __GNUC__
#pragma GCC target("avx2")
#pragma GCC optimize ("O20")
#pragma GCC optimize ("tree-vectorize")
#pragma GCC optimize("unroll-loops")
#define iss std::cin
#endif
#include "bits/stdc++.h"
#define rep(i, times) for(ll i = 0; i < (times); ++i)
using ll = int_fast64_t; using namespace std;

#ifndef __GNUC__
string text =
R"X(8 12 2)X";
stringstream iss{text};
#endif

ll cnt;
int main( ) {
	cin.tie(0);	ios::sync_with_stdio(0);
	ll A, B, K; iss >> A >> B >> K;
	for (ll i = min(A, B); i > 0; --i) {
		if ((A % i == 0) && (B % i == 0)) ++cnt;
		if (cnt == K) {
			cout << i << "\n";
			return 0;
		}
	}
}