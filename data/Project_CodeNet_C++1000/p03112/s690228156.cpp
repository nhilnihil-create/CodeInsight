#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll INF = (1e18) + 10;

int main(void)
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(0);
	
	int n, m, q; cin >> n >> m >> q;
	ll a[n + 2], b[m + 2];
	
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= m; i++)
		cin >> b[i];

	a[0] = -INF;
	b[0] = -INF;
	a[n + 1] = INF;
	b[m + 1] = INF;
	
	int l, r, la, lb, ra, rb, mid;
	ll x, dla, dlb, dra, drb;
	while(q--)
	{
		cin >> x;
		
		l = 0;
		r = n + 1;
		
		la = -1;
		l = 0;
		r = n + 1;
		while(l <= r)
		{
			mid = l + (r - l) / 2;
			if(a[mid] <= x)
			{
				la = mid;
				l = mid + 1;
			}
			else
			{
				r = mid - 1;
			}
		}
		
		lb = -1;
		l = 0;
		r = m + 1;
		while(l <= r)
		{
			mid = l + (r - l) / 2;
			if(b[mid] <= x)
			{
				lb = mid;
				l = mid + 1;
			}
			else
			{
				r = mid - 1;
			}
		}
		
		ra = la + 1;
		rb = lb + 1;
		
		dla = x - a[la];
		dlb = x - b[lb];
		dra = a[ra] - x;
		drb = b[rb] - x;
		
		// cout << la << " " << lb << " " << ra << " " << rb << endl;
		
		cout << min({2*dla + drb, 2*dlb + dra, 2*dra + dlb, 2*drb + dla, max(dla, dlb), max(dra, drb)}) << "\n";
	}
	
	return 0;
}