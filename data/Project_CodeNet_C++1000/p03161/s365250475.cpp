#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,i,k;
    cin>>n>>k;
    int dp[n+1],v[n+1],a=0,p;
    for(int i=0; i<n; i++) cin>>v[i];
    if(n<=k) cout<<abs(v[0]-v[n-1])<<endl;
    else
    {
       for(int i=1; i<=k; i++)
        dp[i] = abs(v[0]-v[i]);

     for(int i=k+1; i<n; i++)
       {
              a = INT_MAX;
              for(int j=i-1; j>=i-k; j--)
             {
                    p = dp[j]+abs(v[i] - v[j]);
                    if(a>p) a = p;
               }
               dp[i] = a;
        }
        cout<<dp[n-1]<<endl;
    }

    return 0;
}

