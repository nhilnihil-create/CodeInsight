#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> T;

const ll mod = 1000000007;
const ll INF = 100000010000;

ll kai[100010];
ll bit[700010];
ll ans[300000];
ll n, a[300000];
ll lar[300000][2][2];

ll sum(ll i)
{
	ll s = 0;
	while (i > 0)
	{
		s += bit[i];
		i -= i & -i;
	}
	return s;
}

void add(ll i, ll x)
{
	while (i <= 700005)
	{
		bit[i] += x;
		i += i & -i;
	}
}

ll gcd(ll x, ll y)
{
	if (y == 0) return x;
	return gcd(y, x % y);
}

ll pow_mod(ll x, ll y)
{
	if (y == 0) return 1;
	if (y % 2 == 1)
	{
		return x * pow_mod(x, y - 1) % mod;
	}
	else
	{
		ll half = pow_mod(x, y / 2);
		return half * half % mod;
	}
}

ll div_mod(ll x)
{
	return pow_mod(x, mod - 2);
}

ll com(ll x, ll y)
{
	return kai[x] * div_mod(kai[y] * kai[x - y] % mod) % mod;
}

void init()
{
	/*kai[0] = 1;
	for (int i = 1; i <= 10000; i++)
	{
		kai[i] = kai[i - 1] * i % mod;
	}*/
	cin >> n;
	for (int i = 0; i < (1 << n); i++)
	{
		cin >> a[i];
	}
}

void output()
{

}

bool cmp(ll x, ll y)
{
	return a[x] > a[y];
}

void solve()
{
	for (int i = 1; i < (1 << n); i++)
	{
		ll num = 0, r;
		for (int j = 0; j < n; j++)
		{
			if ((i & (1 << j)) > 0)
			{
				num++;
				r = j;
			}
		}
		if (num == 1)
		{
			lar[i][0][0] = a[0];
			lar[i][1][0] = a[1 << r];
			lar[i][0][1] = 0;
			lar[i][1][1] = (1 << r);
		}
		else
		{
			ll nu = 0, c[2][2];
			vector<ll> xs;
			for (int j = 0; j < n; j++)
			{
				if ((i & (1 << j)) > 0)
				{
					xs.push_back(lar[i - (1 << j)][0][1]);
					xs.push_back(lar[i - (1 << j)][1][1]);
					
					
					nu++;
					if (nu == 1)
					{
						c[0][0] = lar[i - (1 << j)][0][0];
						c[0][1] = lar[i - (1 << j)][0][1];
						c[1][0] = lar[i - (1 << j)][1][0];
						c[1][1] = lar[i - (1 << j)][1][1];
						if (c[0][0] > c[1][0])
						{
							swap(c[0][0], c[1][0]);
							swap(c[0][1], c[1][1]);
						}
					} 
					else
					{
						if (lar[i - (1 << j)][0][0] > c[0][0] && lar[i - (1 << j)][0][1] != c[0][1] && lar[i - (1 << j)][0][1] != c[1][1])
						{
							c[0][0] = lar[i - (1 << j)][0][0];
							c[0][1] = lar[i - (1 << j)][0][1];
						}
						else if (lar[i - (1 << j)][0][0] > c[1][0] && lar[i - (1 << j)][0][1] != c[0][1] && lar[i - (1 << j)][0][1] != c[1][1])
						{
							c[1][0] = lar[i - (1 << j)][0][0];
							c[1][1] = lar[i - (1 << j)][0][1];
						}

						if (c[0][0] > c[1][0])
						{
							swap(c[0][0], c[1][0]);
							swap(c[0][1], c[1][1]);
						}

						if (lar[i - (1 << j)][1][0] > c[0][0] && lar[i - (1 << j)][1][1] != c[0][1] && lar[i - (1 << j)][1][1] != c[1][1])
						{
							c[0][0] = lar[i - (1 << j)][1][0];
							c[0][1] = lar[i - (1 << j)][1][1];
						}
						else if (lar[i - (1 << j)][1][0] > c[1][0] && lar[i - (1 << j)][1][1] != c[0][1] && lar[i - (1 << j)][1][1] != c[1][1])
						{
							c[1][0] = lar[i - (1 << j)][1][0];
							c[1][1] = lar[i - (1 << j)][1][1];
						}

						if (c[0][0] > c[1][0])
						{
							swap(c[0][0], c[1][0]);
							swap(c[0][1], c[1][1]);
						}
					}

					
				}
			}
			xs.push_back(i);
			if (a[i] > c[0][0])
			{
				c[0][0] = a[i];
				c[0][1] = i;
				if (c[0][0] > c[1][0])
				{
					swap(c[0][0], c[1][0]);
					swap(c[0][1], c[1][1]);
				}
			}

			sort(xs.begin(), xs.end(), cmp);
			xs.erase(unique(xs.begin(), xs.end()), xs.end());

			lar[i][0][0] = a[xs[0]];
			lar[i][0][1] = xs[0];
			lar[i][1][0] = a[xs[1]];
			lar[i][1][1] = xs[1];
		}
	}
	
	ans[0] = 0;
	for (int i = 1; i < (1 << n); i++)
	{
		ans[i] = lar[i][0][0] + lar[i][1][0];
		if (lar[i][1][1] == lar[i][0][1])
		{
			cout << 888888 << ' ' << lar[i][0][1] << endl;
		}
		ans[i] = max(ans[i], ans[i - 1]);
		cout << ans[i] << endl;
	}
}

int main()
{
	init();

	solve();



	output();
	ll N;
	cin >> N;
}