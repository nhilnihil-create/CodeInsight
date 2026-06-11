#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0, i_length = (n); i < i_length; i++)
#define MOD 1000000007
#define ll long long

int main() {
	ll a, b, k;
	cin >> a >> b >> k;
	rep(i, k) {
		if (a % 2 == 1) a--;
		b += a / 2;
		a /= 2;

		swap(a, b);
	}
	if (k % 2 == 1) swap(a, b);

	cout << a << " " << b << endl;

	return 0;
}