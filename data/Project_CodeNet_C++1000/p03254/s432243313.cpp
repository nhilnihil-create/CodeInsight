#include<bits/stdc++.h>
#define int long long
#define fo(i,n)   for(i=0;i<n;i++)
#define mod       1000000007
using namespace std;

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("codefi.txt", "r", stdin);
	freopen("codefo.txt", "w", stdout);
#endif

	int n, x;
	cin >> n >> x;

	int a[n];
	int i;
	fo(i, n)
	cin >> a[i];
	int cnt = 0;
	sort(a, a + n);
	fo(i, n)
	{
		if (x < a[i])
			break;
		x -= a[i];
		cnt++;
	}
	if (x > 0 && cnt == n)
		cnt--;
	cout << cnt << endl;
}