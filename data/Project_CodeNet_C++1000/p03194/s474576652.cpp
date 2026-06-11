#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<bitset>
#include<vector>
#include<deque>
#include<queue>
#include<list>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<iomanip>
#include <functional>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
const int INF = 1 << 28;
const double EPS = 1e-10;
//cout << fixed << std::setprecision(9)
//memset(a, 0, sizeof(a));
//--------------------------

ll Pow(ll x, ll k)
{
	if (k == 0)     return 1;
	if (k % 2 == 0) return Pow(x*x, k / 2);
	else            return x*Pow(x, k - 1);
}


int main()
{
	ll n, p;
	ll ans = 1;
	cin >> n >> p;

	if (n == 1) {
		cout << p << endl;
		return 0;
	}

	if (n > 40) {
		cout << 1 << endl;
		return 0;
	}

	ll a = 2;
	while (a * a <= p) {
		if (p%a == 0) {
			ll div = Pow(a, n);
			while (p%div==0) {
				p /= div;
				ans *= a;
			}
		}
		a++;
	}

	cout << ans << endl;

	return 0;
}
