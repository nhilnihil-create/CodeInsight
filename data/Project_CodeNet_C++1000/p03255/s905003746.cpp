#include <iostream>
using namespace std;

long long n, m, s;
long long a[200000], b[200000];

int main()
{
	cin >> n >> m;

	unsigned long long t = 2 * n * m;

	for (long long i = 0; i < n; i++)
		cin >> a[i];

	b[n - 1] = a[n - 1];

	for (long long i = 1; i < n; i++)
		b[n - 1 - i] = b[n - i] + a[n - 1 - i];

	t += 5 * b[0];

	for (long long k = 1; k < n; k++) {
		unsigned long long t1 = (n + k) * m;

		for (long long i = 1; i < n / k; i++)
			t1 += (2 * i + 3) * (b[n - (i + 1) * k] - b[n - i * k]);

		t1 += 5 * b[n - k] + (2 * (n / k) + 3) * (b[0] - b[n % k]);

		if (t1 < t)
			t = t1;
	}

	cout << t << endl;

	return 0;
}