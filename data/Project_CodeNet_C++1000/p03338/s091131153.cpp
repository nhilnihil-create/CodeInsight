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
	str s;
	cin >> s;
	map<char, int> y;
	rep(i, s.size())
	{
		y[s[i]]++;
	}
	map<char, int> x;
	ll ans = 0;
	rep(i, s.size())
	{
		x[s[i]]++;
		y[s[i]]--;
		ll tmp_ans = 0;
		for (auto xxx : x)
		{
			if (y[xxx.first] > 0)
			{
				tmp_ans++;
			}
		}
		ans = max(tmp_ans, ans);
	}
	cout << ans << endl;
	return 0;
}