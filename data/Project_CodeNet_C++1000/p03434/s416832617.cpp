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


	int n;
	cin >> n;

	int a[n];
	int i;
	fo(i, n)
	cin >> a[i];

	sort(a, a + n, greater<int>());
	int alice = 0, bob = 0;
	for (int i = 0; i < n; i ++)
	{
		if (i % 2 == 0)
			alice += a[i];
		else
			bob += a[i];
	}
	cout << abs(alice - bob) << endl;
}