/* BISMILLAHIR RAHMANIR RAHIM */
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int dp[n];
    vector<int>ar(n);
    for(int i=0; i<n; i++)
        cin>>ar[i];

    dp[0]=0;
  //  dp[1]=abs(ar[1]-ar[0]);

    for(int i=1; i<=n-1; i++)
    {
        if(i-2>=0)
            dp[i]=min(dp[i-1]+abs(ar[i]-ar[i-1]),dp[i-2]+abs(ar[i]-ar[i-2]));
      else
             dp[i]=abs(ar[i]-ar[i-1]);

    }
    cout<<dp[n-1];
    return 0;
}
