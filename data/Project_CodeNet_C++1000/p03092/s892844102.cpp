#include <bits/stdc++.h>

using namespace std;

#define int long long

int n,a,b;
int p[5001], f[10011], mn[10011], pos[5001];

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> a >> b;
	for (int i=1;i<=n;i++)
	{
		cin >> p[i];
		pos[p[i]] = i*2;
	}
	mn[0] = 1e18;
	for (int j=1;j<=n;j++)
	{
    	for (int i=1;i<=2*n+1;i++)
    	{
    		int cost = 0;
    		if (i < pos[j]) cost = b;
    		else if (i > pos[j]) cost = a;
    		if (i%2 == 1)
    			f[i] = mn[i] + cost;			
    		else
    			f[i] = mn[i-1] + cost;
    	}
		for (int i=1;i<=2*n+1;i++)
			mn[i] = min(mn[i-1],f[i]);
	}
	cout << mn[2*n+1];	
}