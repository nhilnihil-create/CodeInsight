#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int n;
int a[maxn], b[maxn], c[maxn];
ll ans;
void solve(int x)
{
	int r = (1 << x) - 1, l = 1 << (x - 1);
	for(int i = 1; i <= n; ++i) c[i] = b[i] & r;
	sort(c + 1, c + n + 1);
	ll tot = 0;
	for(int i = 1; i <= n; ++i)
	{
		int L = l - (a[i] & r); while(L < 0) L += 1 << x;
		int R = r - (a[i] & r); while(R < 0) R += 1 << x;
		if(L <= R)
			tot += upper_bound(c + 1, c + n + 1, R) - lower_bound(c + 1, c + n + 1, L);
		else
			tot += upper_bound(c + 1, c + n + 1, R) + n - lower_bound(c + 1, c + n + 1, L);
	}
	if(tot & 1) ans |= l;
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for(int i = 1; i <= n; ++i) scanf("%d", &b[i]);
	for(int i = 1; i <= 29; ++i)
		solve(i);
	cout << ans << endl;
	return 0;
}