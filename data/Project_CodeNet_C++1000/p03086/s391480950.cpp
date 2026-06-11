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
R"X(HATAGAYA)X";
stringstream iss{text};
#endif

ll maxl;
int main( ) {
	cin.tie(0);	ios::sync_with_stdio(0);
	//ll N; iss >> N;
	string s; iss >> s;
	regex  re("(A|G|C|T)+");
	sregex_iterator it(begin(s), end(s), re);
	sregex_iterator end;
	for (; it != end; ++it) {
		auto &&m = *it;
		maxl = max(maxl, m.length( ));
	}
	cout << maxl << "\n";
}
