#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e3 + 5;

int n, k;
int a[N], b[N];

int cnt(int x)
{
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		int cur = 0;
		for(int j = i; j <= n; j++)
		{
			cur += a[j];
			if((cur & x) == x)
				cnt++;
		}
	}
	return cnt >= k;
}

int32_t main()
{
	IOS;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int ans = 0, mask = 0;
	for(int i = 50; i >= 0; i--)
	{
		if(cnt(mask + (1LL << i)))
			mask += (1LL << i);
	}
	cout << mask;
	return 0;
}