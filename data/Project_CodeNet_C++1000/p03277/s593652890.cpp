#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,sz;
int a[100001], b[100001], p[100001];
int BIT[200001];

void update(int x)
{
	if (x == 0) x = 1;
	for(;x<=200000;x+=x&(-x))	
		BIT[x]++;
	return;
}

int query(int x)
{
	int ans = 0;
	for(;x>0;x-=x&(-x))
		ans += BIT[x];
	return ans;
}

bool check(int x)
{
	for (int i=1;i<=n;i++)
	{
		if (a[i] >= x)
			b[i] = 1;
		else
			b[i] = 0;
		p[i] = p[i-1] + b[i];
	}
	for (int i=0;i<=200000;i++)
		BIT[i] = 0;
	update(100000);
	int cur = 0;
	for (int i=1;i<=n;i++)
	{
		cur += query(2*p[i] - i + 100000);
		update(2*p[i] - i + 100000);
	}
	return (cur >= sz);
}

int32_t main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for (int i=1;i<=n;i++)
		cin >> a[i];
	sz = n*(n+1)/2;
	sz = (sz+1)/2;
	int l = 1, r = 1e9;
	int res;
	while(l <= r)
	{
		int mi = (l+r)/2;
		if (check(mi))
		{
			res = mi;
			l = mi + 1;
		}
		else
			r = mi - 1;
	}
	cout << res;
	return 0;
}
