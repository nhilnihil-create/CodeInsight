#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll gcd(ll a, ll b) {
	if (b > a) return gcd(b, a);
	if (b == 0) return a;
	return gcd(b, a % b);
}

void solve() {
	ll A, B, C, D;
	cin >> A >> B >> C >> D;
	if (A < B) { // 開店時に買えない
		cout << "No" << endl;
		return;
	}
	if (D < B) { // 補充が明らかに不足
		cout << "No" << endl;
		return;
	}
	// 毎日の開店時の本数はgcd(A,B,D)の倍数なので、
	// A,B,C,Dをgcd(A,B,D)で割っても答えは不変
	ll g = gcd(gcd(A, B), D);
	A /= g, B /= g, C /= g, D /= g;
	if (C >= B - 1) { // 十分量があるときに十分量補充される
		cout << "Yes" << endl;
		return;
	}
	// 開店時の本数が(C,B)になると次の日に買えなくなる
	if ((A - C - 1) / B >= (A - B + 1) / B + ((A - B + 1) % B ? 1 : 0)) {
		cout << "No" << endl;
		return;
	}
	if (D % B == 0) {
		cout << "Yes" << endl;
		return;
	}
	if (gcd(D % B, B) == 1) {
		cout << "No" << endl;
		return;
	}
	if (C + 1 <= A % B && A % B <= B - 1) {
		cout << "No" << endl;
		return;
	}
	if (gcd(D % B, B) <= B - C - 1) {
		cout << "No" << endl;
		return;
	}
	cout << "Yes" << endl;
}

int main() {
	int T; cin >> T;
	while (T--) solve();
	return 0;
}