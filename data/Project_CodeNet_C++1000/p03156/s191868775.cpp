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
	int n, a, b;
	cin >> n >> a >> b;
	veci p(n);
	rep(i, n) cin >> p[i];
	sort(all(p));
	int aaa, bbb, ccc;
	aaa = bbb = ccc = 0;
	for (int i = 0; i < n; i++)
	{
		if (p[i] <= a)
			aaa++;
		if (a < p[i] && p[i] <= b)
			bbb++;
		if (p[i] > b)
			ccc++;
	}
	cout << min({aaa, bbb, ccc}) << endl;
	return 0;
}