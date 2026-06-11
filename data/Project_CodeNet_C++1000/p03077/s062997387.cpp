#include <bits/stdc++.h>
using namespace std;

int main()
{
	int64_t n, a, b, c, d, e;
	cin >> n >> a >> b >> c >> d >> e;

	int64_t x = min({a, b, c, d, e});

	cout << 5 + (n + x - 1) / x - 1 << endl;

	return 0;
}