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

	ll n; cin >> n;
	vector<ll> a(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	// 3つ以上の整数の場合
	long long gcd = a[0];
	for (int i = 1; i < n; i++) {
		gcd = GetGreatestCommonDivisor(gcd, a[i]);
	}	
	cout << gcd << endl;
	return 0;
}