#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 2つの整数の場合
long long GetGreatestCommonDivisor(long long a, long long b)
{
	long long m = a;
	long long n = b;
	long long temp;

	while (m % n != 0) {
		temp = n;
		n = m % n;
		m = temp;
	}
	return n;
}

int main() {

	ll n, z; cin >> n >> z;
	vector<ll> x(n + 1);
	for (ll i = 0; i < n; i++) {
		cin >> x[i];
	}
	x[n] = z;
	sort(x.begin(), x.end());
	vector<ll> d(n);
	for (int i = 0; i < n; i++) {
		d[i] = x[i + 1] - x[i];
	}
	// 3つ以上の整数の場合
	long long gcd = d[0];
	for (int i = 1; i < n; i++) {
		gcd = GetGreatestCommonDivisor(gcd, d[i]);
	}
	cout << gcd << endl;
	return 0;
}