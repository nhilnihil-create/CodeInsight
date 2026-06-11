#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long


const int Mod = 1e9+7;

int n, k;
int a[101];
int dp[101][100001];


int32_t main()
{
      IOS;

      cin>>n>>k;
      for(int i=0; i<n; i++)
      	cin>>a[i];

      for(int i=0; i<=a[0]; i++)
      	dp[0][i] = 1;

      for(int i=1; i<n; i++)
      {
      	vector<int> pref(k+1); //dp prefix sum optimization technique
      	pref[0] = dp[i-1][0];
      	for(int j=1; j<=k; j++)
      		pref[j] = (pref[j-1] + dp[i-1][j]) % Mod;

      	for(int j=0; j<=k; j++)
      	{
      		if(j-a[i]>0) dp[i][j] = (pref[j]-pref[j-a[i]-1] + Mod) % Mod;
      		else dp[i][j] = pref[j];
      	}
      }

      int ans= dp[n-1][k];

      cout<<ans;



      return 0;
}
