#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b;
ll f(ll a, ll b) {
	ll sum = 0;
	for (ll i = a; i <= b; i ++) sum ^= i;
	return sum;
}
int main() {
	cin >> a >> b;
	ll x = f(b - b % 4, b);
	ll y = f(a - 1 - (a - 1) % 4, a - 1);
	cout << (x ^ y) << endl;
}