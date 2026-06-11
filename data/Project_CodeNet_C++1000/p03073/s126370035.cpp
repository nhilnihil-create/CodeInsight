#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using str = string;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
const double PI = 3.141592653589793238;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define REP(i, m, n) for (int i = m; i < (int)n; i++)
#define all(a) (a).begin(), (a).end()
#define allg(a) (a).begin(), (a).end(), greator<>()
#define d20 std::setprecision(20)
#define veci vector<int>
#define vecll vector<long long int>
#define vecb vector<bool>
#define vecd vector<double>
template <typename T>
T lcm(T a, T b)
{
	return a / __gcd(a, b) * b;
}
void comb(vector<vector<long long int>> &v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		v[i][0] = 1;
		v[i][i] = 1;
	}
	for (size_t k = 1; k < v.size(); k++)
	{
		for (size_t j = 1; j < k; j++)
		{
			v[k][j] = (v[k - 1][j - 1] + v[k - 1][j]);
		}
	}
}
ll repeat_squaring(ll n, ll p, ll m)
{
	if (p == 0)
		return 1;
	if (p % 2 == 0)
	{
		ll t = repeat_squaring(n, p / 2, m);
		return t * t % m;
	}
	return n * repeat_squaring(n, p - 1, m);
}

int main()
{
	str s;
	cin >> s;
	int ans = 0, ans2 = 0;
	char x = '1';
	rep(i, s.size())
	{
		if (s[i] == x)
		{
			ans++;
		}
		else
		{
			ans2++;
		}
		if (x == '1')
		{
			x = '0';
		}
		else
		{
			x = '1';
		}
	}
	cout << min(ans, ans2) << endl;
	return 0;
}