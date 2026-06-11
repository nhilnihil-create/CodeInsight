#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

long long gcd(int x, int y)
{
	if (y == 0) return x;
	return gcd(y, x%y);
}
long long lcm(int x, int y)
{
	return x * y / gcd(x, y);
}
signed main(void)
{
	int n;
	cin >> n;
	cout << (long long)lcm(2, n) << endl;
	return 0;
}
