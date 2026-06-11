#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pb push_back
typedef pair<int, int> ii;
typedef long long ll;

const int maxn = 2e5+5;

int n, x;

ll arr[maxn];

int main()
{
	scanf("%d %d", &n, &x);
	for(int i = 1; i<= n; i++) scanf("%lld", arr+i);
	for(int i = 1; i<= n; i++) arr[i] += arr[i-1];
	ll best = 4e18;
	for(int k = 1; k<= n; k++)
	{
		ll base = 1LL*(k+n)*x;
		int rounds = (n+k-1)/k;
		for(int r = 1; r<= rounds; r++)
		{
			int st = (r-1)*k+1;
			int ed = k*r;
			int val = r==1?5:(2*r+1);
			st = n+1-st;
			ed = max(1, n+1-ed);
			// printf("%d %d\n", ed, st);
			base += 1LL*(arr[st]-arr[ed-1])*val;
			if(base> best) break;
		}
		// printf("%d %lld\n", k, base);
		best = min(best, base);
	}
	printf("%lld\n", best);
}