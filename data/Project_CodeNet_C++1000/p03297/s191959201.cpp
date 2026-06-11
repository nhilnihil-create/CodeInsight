#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(V) (V).begin(),(V).end()

bool solve(ll a, ll b, ll c, ll d) {
	if (a < b)return 0;
	if (b > d)return 0;
	if (c < b - 1)return 0;
	return 1;
}

ll gcd(ll x, ll y) {
	while (y) {
		x %= y;
		swap(x, y);
	}
	return x;
}

queue<string> Q;

int main(){
	ll A, B, C, D, E;
	int T;
	cin >> T;
	for (int i = 0;i < T;i++) {
		cin >> A >> B >> C >> D;
		E = gcd(B, D);
		C -= A % E;
		A /= E;
		B /= E;
		if (C < 0)C = -1;
		else C /= E;
		D /= E;
		if (solve(A, B, C, D))
			Q.push("Yes");
		else
			Q.push("No");
	}
	while (!Q.empty()) {
		cout << Q.front() << endl;
		Q.pop();
	}
}