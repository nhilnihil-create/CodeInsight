#pragma GCC optimize("Ofast", "unroll-loops")

#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
	string S; cin >> S;
	ll K; cin >> K;
	for (int i = 0; i < K - 1; ++i) {
		if (S[i] != '1') {
			cout << S[i] << endl;
			return 0;
		}
	}
	cout << S[K - 1] << endl;
	return 0;
}