#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
typedef long long ll;
int L, edge;
const ll mod = 1000000007;
vector<int> bit;

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
	cin >> L;
	while (L)
	{
		bit.push_back(L % 2);
		edge += L % 2;
		L /= 2;
	}
	cout << bit.size() << ' ';
	cout << edge - 1 + 2 * (bit.size() - 1) << endl;
	for (int i = 1; i < bit.size(); i++)
	{
		cout << i << ' ' << i + 1 << ' ' << 0 << endl;
		cout << i << ' ' << i + 1 << ' ' << pow(2, i - 1) << endl;
	}
	int weight = pow(2, bit.size() - 1);
	for (int i = bit.size() - 2; i >= 0; i--)
	{
		if (bit[i] == 1)
		{
			cout << i + 1 << ' ' << bit.size() << ' ' << weight << endl;
			weight += pow(2, i);
		}
	}
	int www;
	cin >> www;
}
