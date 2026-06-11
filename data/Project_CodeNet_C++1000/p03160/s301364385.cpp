#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,i;
    cin>>n;
    int dp[n+1],v[n+1],a=0,b=0,p;
    for(int i=0; i<n; i++) dp[i] = INT_MAX;
    for(int i=0; i<n; i++) cin>>v[i];
    if(n==2) cout<<abs(v[0]-v[1])<<endl;
    else
    {
        dp[1] = abs(v[0]-v[1]);
        dp[2] = abs(v[0]-v[2]);
        for(int i=3; i<n; i++)
        {
            p = dp[i-2]+abs(v[i] - v[i-2]);
           a = dp[i-1] + abs(v[i] - v[i-1]);
           dp[i] = min(p,a);
        }
        cout<<dp[n-1]<<endl;
    }

    return 0;
}
