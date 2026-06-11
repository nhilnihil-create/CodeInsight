#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
const int MAXN = (int)2e5 + 10;
const int infint = (int)1e9;
const ll inf = (ll)1e18;
ll n, a[MAXN], b[MAXN];
bool equal()
{
	for (int i = 0; i < n; i++)
		if(a[i] != b[i])
			return 0;
	return 1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i] >> b[i];
	if(equal())	
		return cout << 0, 0;
	ll ans = 0;
	for (int i = 0; i < n; i++)
		ans += a[i];
	ll mn = inf;
	for (int i = 0; i < n; i++)
		if(b[i] < a[i])
			mn = min(mn, b[i]);
			
	cout << ans - mn;
}