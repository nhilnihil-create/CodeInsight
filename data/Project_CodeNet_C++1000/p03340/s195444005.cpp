#include<bits/stdc++.h>
using namespace std;

const int maxn = 2 * 1e5 + 1;

long long n, num[maxn] = {}, pl[maxn] = {}, xo[maxn] = {};

int main()
{
	cin >> n;
 	for (int i = 1; i <= n; i++)
 	{
 		cin >> num[i];
 		pl[i] = xo[i] = num[i];
 		pl[i] += pl[i - 1];
 		xo[i] ^= xo[i - 1];
	}
	
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int l = i, r = n, best = -1;
		while (l <= r)
		{
			
			int mid = (l + r) / 2 ;
			//cout << l << ' ' << r << ' ' << mid << '\n'; 
			if ((pl[mid] - pl[i - 1]) == (xo[mid] ^ xo[i - 1]))
			{	
				best = mid;
				l = mid + 1;
			}
			else 
			{
				r = mid - 1;
			}
			
		}
		
		ans += best - i + 1;
	}
		
	cout << ans << '\n';
	return 0;
}