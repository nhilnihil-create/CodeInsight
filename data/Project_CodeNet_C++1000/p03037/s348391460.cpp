#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, m, cnt = 0;
int f[N];

int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int l, r;
		cin >> l >> r;
		f[l]++;
		f[r + 1]--;
	}
	for(int i = 1; i <= n; i++)
	{
		f[i] += f[i - 1];
		if(f[i] == m)
			cnt++;
	}
	cout << cnt;
	return 0;
}
