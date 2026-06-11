#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b);

int main()
{
	int n;
	cin >> n;

	vector<int> a(n), l(n), r(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < n; i++) {
		l[i] = gcd(l[i - 1], a[i - 1]);
	}
	for (int i = n - 2; i >= 0; i--) {
		r[i] = gcd(r[i + 1], a[i + 1]);
	}

	long long mx = 0;
	for (int i = 0; i < n; i++) {
		mx = max(mx, gcd(r[i], l[i]));
	}
	cout << mx << endl;

	return 0;
}

long long gcd(long long a, long long b)
{
	if (a < b) {
		long long t = a;
		a = b;
		b = t;
	}

	if (b == 0) {
		return a;
	}

	long long r = a % b;
	while (r != 0) {
		a = b;
		b = r;
		r = a % b;
	}

	return b;
}