#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	if (a % b == 0)return b;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}

int main() {
	ll N, M;
	string S, T;
	cin >> N >> M >> S >> T;

	ll l = lcm(N, M);
	if (gcd(N, M) == 1) {
		if (S.front() != T.front())cout << -1 << endl;
		else cout << l << endl;
	}
	else {
		if (N > M)swap(S, T), swap(N, M);
		for (int i = 0; i < gcd(N, M); i++) {
			if (S[i * (lcm(N, M) / M)] != T[i * lcm(N, M) / N]) {
				cout << -1 << endl;
				return 0;
			}
		}
		cout << l << endl;
	}
	return 0;
}