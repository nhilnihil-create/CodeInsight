#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1000000007;
const double PI = acos(-1);

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	if (c <= a + b) cout << b + c << endl;
	else cout << a + 2 * b + 1 << endl;
}
