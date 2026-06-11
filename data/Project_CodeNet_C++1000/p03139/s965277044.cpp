#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
int n, a, b;
const ll mod =1000000007;

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
	cin >> n >> a >> b;
	cout << min(a, b) << ' ';
	cout << max(0, a + b - n) << endl;
	int www;
	cin >> www;
}
