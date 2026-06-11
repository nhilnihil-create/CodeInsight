#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx")
#include <bits/stdc++.h>
constexpr int INF = 2147483647;
constexpr long long int INF_LL = 9223372036854775807;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

//12341234
int main() {
	int M, K;
	cin >> M >> K;
	if ((1 << M) <= K || (M == 1 && K == 1)) {
		cout << -1 << endl;
		return 0;
	}
	if (K == 0) {
		for (int i = 0; i < (1 << M); i++) {
			cout << i << endl << i << endl;
		}
		return 0;
	}
	for (int i = 0; i < (1 << M); i++) {
		if (i != K)cout << i << endl;
	}
	cout << K << endl;
	for (int i = (1 << M) - 1; i >= 0; i--) {
		if (i != K)cout << i << endl;
	}
	cout << K << endl;
}