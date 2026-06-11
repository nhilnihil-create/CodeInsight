#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

int n;
int a[300001];
ii f[300001];

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for (int i=0;i<(1<<n);i++)
	{
		cin >> a[i];
		f[i].first = a[i];
	}
	for (int i=0;i<=17;i++)
		for (int mask=1;mask<(1<<n);mask++)
			if ((1<<i) & mask)
			{
				if (f[mask ^ (1<<i)].first > f[mask].first)
				{
					f[mask].second = max(f[mask].first,f[mask ^ (1<<i)].second);
					f[mask].first = f[mask ^ (1<<i)].first;
				}
				else
					f[mask].second = max(f[mask].second,f[mask ^ (1<<i)].first);
			}
	int mx = 0;
	for (int i=1;i<(1<<n);i++)
	{
		mx = max(mx,f[i].first + f[i].second);
		cout << mx << '\n';
	}
	return 0;
}