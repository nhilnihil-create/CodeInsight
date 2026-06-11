#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;

int T;

ll gcd(ll a, ll b) {
	if (a % b == 0)return b;
	return gcd(b, a % b);
}

bool ok(ll a, ll b, ll c, ll d) {
	if (b > d) {
		return false;
	}
	else if (b == d) {
		if (a % b <= c)return true;
		else return false;
	}
	else {
		ll G = gcd(b, d);
		if (c < b - G || (a % b) > c || a < b)return false;
		return true;
	}
}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		ll A, B, C, D;
		cin >> A >> B >> C >> D;
		if (ok(A, B, C, D))cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}