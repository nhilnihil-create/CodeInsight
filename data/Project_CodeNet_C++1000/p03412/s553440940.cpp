#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
ll a[200010];
ll b[200010];
int main()
{
	ll n;
	scanf("%lld", &n);
	for (ll i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	for (ll i = 0; i < n; i++)
		scanf("%lld", &b[i]);
	ll dap = 0;
	for (ll i = 1; i <= 30; i++)
	{
		ll ch = ((ll)1 << (i-1));
		vector<ll> vt;
		for (ll y = 0; y < n; y++)
			vt.push_back(a[y] % ((ll)1 << i));
		vt.push_back((1 << 30));
		sort(vt.begin(), vt.end());
		ll gap = 0;
		for (ll y = 0; y < n; y++)
		{
			ll ch1 = b[y] % ((ll)1 << i);
			ll t = lower_bound(vt.begin(), vt.end(), ch - ch1) - vt.begin();
			ll o = upper_bound(vt.begin(), vt.end(), ((ll)1<<i)-ch1-1) - vt.begin();
			o--;
			if (o >= t) {
				gap = gap + (o - t) + 1;
			}
			t = lower_bound(vt.begin(), vt.end(), ch - ch1 +((ll)1<<i)) - vt.begin();
			o = upper_bound(vt.begin(), vt.end(), ((ll)1 << i) * 2 - ch1 - 1) - vt.begin();
			o--;
			if(o>=t)
				gap += (o - t+1);
		}
		if (gap % 2)
			dap += ((ll)1 << (i - 1));
	}
	printf("%lld", dap);
}