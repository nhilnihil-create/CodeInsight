#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
int dp[100][100005];
int main()
{
    int n,k;
    cin>>n>>k;
      int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    for(int i=0;i<=a[0];i++)
      dp[0][i] = 1;
    
    for(int i=1;i<n;i++){
      vector<int>pref(k+1);
      pref[0] = dp[i-1][0];
      for(int j=1;j<=k;j++){
        pref[j] = (pref[j-1]+dp[i-1][j])%MOD;
      }

      for(int j=0;j<=k;j++){
        if(j>a[i])
        dp[i][j] = (pref[j]+MOD - pref[j-a[i]-1])%MOD;
        else
        {
          dp[i][j] = pref[j];
        }
        
      }
    }

    cout<<dp[n-1][k];

    return 0;
}