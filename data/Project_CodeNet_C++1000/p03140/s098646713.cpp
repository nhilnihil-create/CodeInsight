#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
typedef long long ll;
int n, ans;
const ll mod =1000000007;
string a, b, c;

ll pow(ll x, ll y)
{
	if (y == 0) return 1;
	if (y % 2)
	{
		return pow(x, y - 1) * x % mod;
	}
	else
	{
		ll yyy = pow(x, y / 2);
		return yyy * yyy % mod;
	}
}

ll div(ll x)
{
	return pow(x, mod - 2);
}

int main(void)
{
	cin >> n >> a >> b >> c;
	for (int i = 0; i < n; i++)
	{
		int same = 0;
		if (a[i] == b[i]) same++;
		if (b[i] == c[i]) same++;
		if (c[i] == a[i]) same++;
		if (same == 0) ans += 2;
		if (same == 1) ans += 1;
	}
	cout << ans << endl;
	int www;
	cin >> www;
}
