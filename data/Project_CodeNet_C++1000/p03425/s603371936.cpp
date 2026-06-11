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

int main()
{
	int n;
	cin >> n;
	ll m, a, r, c, h;
	m = a = r = c = h = 0;
	rep(i, n)
	{
		str tmp;
		cin >> tmp;
		switch (tmp[0])
		{
		case 'M':
			m++;
			break;
		case 'A':
			a++;
			break;
		case 'R':
			r++;
			break;
		case 'C':
			c++;
			break;
		case 'H':
			h++;
			break;
		default:
			break;
		}
	}
	ll ans = 0;
	ans += m * a * r;
	ans += m * a * c;
	ans += m * a * h;
	ans += m * r * c;
	ans += m * r * h;
	ans += m * c * h;
	ans += a * r * c;
	ans += a * r * h;
	ans += a * c * h;
	ans += r * c * h;
	cout << ans << endl;
	return 0;
}