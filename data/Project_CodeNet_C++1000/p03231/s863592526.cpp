#include <bits/stdc++.h>
using namespace std;
#define all(V) V.begin(),V.end()
using ll = long long;
const ll MOD = 1000000007;

ll gcd(ll x, ll y) {
	while (y) {
		x %= y;
		swap(x, y);
	}
	return x;
}

int main() {
	ll N, M, G;
	cin >> N >> M;
	G = gcd(N, M);
	string S, T;
	cin >> S >> T;

	string ns, nt;
	for (int i = 0;i < G;i++) {
		ns += S[i * (N / G)];
		nt += T[i * (M / G)];
	}
	if (ns == nt) {
		cout << N / G * M << endl;
	}
	else {
		cout << -1 << endl;
	}
}