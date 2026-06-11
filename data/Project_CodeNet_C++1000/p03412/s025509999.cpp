#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
typedef long long ll;
using namespace std;
ll a[200010], b[200010];
ll tmp[200010];
int n;
inline ll chk(ll k)
{
	register int l = 1, r = n + 1;
	while (l < r)
	{
		register int mid = (l + r) >> 1;
		if (tmp[mid] >= k)r = mid; else l = mid + 1;
	}
	return l;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n; 
	for (register int i = 1; i <= n; i++) cin >> a[i];
	for (register int i = 1; i <= n; i++) cin >> b[i];
	register ll ans = 0;
	for (register int k = 1; k <= 29; k++)
	{
		register ll base = (1 << k) - 1;
		for (register int i = 1; i <= n; i++)tmp[i] = b[i] & base;
		sort(tmp + 1, tmp + n + 1);
		register ll cnt = 0;
		for (register int i = 1; i <= n; i++)
			cnt += n - chk((1 << (k - 1)) - (a[i] & base)) + 1;
		for (register int i = 1; i <= n; i++)
			cnt -= chk((1 << k) + (1 << (k - 1)) - (a[i] & base)) - chk((1 << k) - (a[i] & base));
		if (cnt & 1) ans += (1 << (k - 1));
	}
	cout << ans << endl; return 0;
}