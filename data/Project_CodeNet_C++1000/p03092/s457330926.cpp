#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
 
const int maxn = 5e3 + 20;

ll dp[maxn] , a[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	ll x , y;
	cin >> n >> x >> y;

	for(int i = 1; i <= n; i++)
		cin >> a[i];

	a[n + 1] = n + 1;
	memset(dp , 63 , sizeof dp);
	dp[0] = 0;
	for(int i = 1; i <= n + 1; i++)
	{
		int mx = -1 , t = 0;
		for(int j = i - 1; j >= 0; j--)
		{
			if(a[j] > a[i])
				t++;
			else if(a[j] > mx)
			{
				mx = a[j];
				dp[i] = min(dp[i] , dp[j] + t * x + (i - j - 1 - t) * y);
			}
		}
	}

	cout << dp[n + 1] << endl;
}
















