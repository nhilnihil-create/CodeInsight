#include <bits/stdc++.h>
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
using namespace std;
using cd = complex <double>;
 
typedef pair <int, int> pii;
const int N = 3e3 + 5;
const long long INF = 1e18;
const int mod = 1e9 + 7;//786433;//998244353;
const double Pi = acos(-1);
const int p = 510200;
 
void Fastio()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int n;
int a[100005];
vector <int> Div;

signed main()
{
	Fastio();
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int ans = a[2];
	for(int i = 3; i <= n; i++)
	{
		ans = __gcd(ans, a[i]);
	}
	for(int i = 1; i <= sqrt(a[1]); i++)
	{
		if(a[1] % i == 0)
		{
			Div.eb(i);
			Div.eb(a[1] / i);
		}
	}
	for(auto x : Div)
	{
		int cnt = 0;
		for(int i = 1; i <= n; i++)
		{
			if(a[i] % x == 0)
			{
				cnt++;
			}
		}
		if(cnt >= n - 1)
		{
			ans = max(ans, x);
		}
	}
	cout << ans;
}