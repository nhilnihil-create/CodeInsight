#include<iostream>
#include<algorithm>
#include<cstring>
#include<stack>
#include<cmath>
#include<queue>
#include<map>
using namespace std;
#define ll long long
#define N 2000005
#define rep(i,l,r) for(i=l;i<=r;i++)
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
#define eps 0.00000001//偏差值1e8
#define pi acos(-1.0)//高精度圆周率
const int maxp = 1010;					//点的数量
ll a[N];
ll b[N];
ll c[N];
int main()
{
	ll i, j, k;
	ll n, ret = 0, maxn = 0, count = 0;
	ll ans = 0;
	ll t, x, y, len, pos = mod;
	cin >> n >> k;
	if (k == 0)ans = n * n;
	else
	{
		for (i = k + 1; i <= n; i++)
		{
			ans += (n / i) * (i - k);
			if (n % i >= k)ans += n % i - k + 1;
		}
	}
	cout << ans << endl;
}
		

	