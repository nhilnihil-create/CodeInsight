// ABC_110_A

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	int maxi = max(a, max(b, c));

	cout << 10 * maxi + a + b + c - maxi << "\n";

	return 0;
}
