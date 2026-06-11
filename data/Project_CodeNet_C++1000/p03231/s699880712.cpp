#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

/* aとbの最大公約数を求める. */
ll gcd(ll a, ll b) {
	if (b > a) return gcd(b, a);
	if (b == 0) return a;
	return gcd(b, a % b);
}

/* aとbの最小公倍数を求める. */
ll lcm(ll a, ll b) {
	ll g = gcd(a, b);
	return (a / g) * b;
}

int main() {
	int N, M;
	cin >> N >> M;
	ll L = lcm(N, M);
	ll G = gcd(N, M);
	string S, T;
	cin >> S >> T;
	int m = (int)M / G;
	int n = (int)N / G;
	for (int j = 0; j < M; j += m) {
		int i = j / m * n;
		if (S[i] != T[j]) {
			cout << -1 << endl;
			return 0;
		}
	}
	cout << L << endl;
	return 0;
}