#include<iostream>
#include<algorithm>
#include<cstdio>
#define ll long long 
using namespace std;
const int maxn = 2e5 + 10;

ll a[maxn];

int main()
{
	int N; cin >> N;
	a[0] = 0;
	for (int i = 1; i <= N; i++) cin >> a[i];
	for (int i = 1; i <= N; i++) a[i] += a[i - 1];
	ll ans = 1e15;
	
	for (int k = 2; k <= N - 2; k++)
	{
		ll SL = a[k]; ll SR = a[N] - a[k];
		//L
		int l = lower_bound(a + 1, a + 1 + k, SL / 2) - a;
		if (l == k)l -= 1;
		ll sL1 = a[l]; ll sL2 = a[k] - a[l];
		if (l != 1)
		{
			if (abs(a[l - 1] - (a[k] - a[l - 1])) < abs(sL2 - sL1))
			{
				sL1 = a[l - 1]; sL2 = a[k] - a[l - 1];
			}
		}
		//R
		int r = lower_bound(a + 1 + k, a + 1 + N, SR / 2 + SL) - a;
		if (r == N)r -= 1;
		ll sR1 = a[r] - a[k]; ll sR2 = a[N] - a[r];
		if (r != k + 1)
		{
			if (abs((a[r - 1]-a[k]) - (a[N] - a[r - 1])) < abs(sR2 - sR1))
			{
				sR1 = a[r - 1] - a[k];
				sR2 = a[N] - a[r - 1];
			}
		}

		ll smax = max(max(sL1, sL2), max(sR1, sR2));
		ll smin = min(min(sL1, sL2), min(sR1, sR2));
		ans = min(ans, smax - smin);
	}
	cout << ans << endl;
	return 0;
}