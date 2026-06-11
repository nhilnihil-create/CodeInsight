#include <iostream>
#include <string>

using namespace std;

long long gcd(long long a, long long b);
long long lcm(long long a, long long b);

int main()
{
	int n, m;
	string s, t;
	cin >> n >> m >> s >> t;

	int g = gcd(n, m);
	int p = n / g, q = m / g;
	for (int i = 0; i < g; i++) {
		if (s[i * p] != t[i * q]) {
			cout << -1 << endl;
			return 0;
		}
	}
	cout << lcm(n, m) << endl;

	return 0;
}

long long gcd(long long a, long long b)
{
	if (a < b) {
		long long t = a;
		a = b;
		b = t;
	}

	long long r = a % b;
	while (r != 0) {
		a = b;
		b = r;
		r = a % b;
	}

	return b;
}

long long lcm(long long a, long long b)
{
	return a / gcd(a, b) * b;
}