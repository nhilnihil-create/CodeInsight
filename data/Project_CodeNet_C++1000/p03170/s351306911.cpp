#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    vector<int> dp(100005,-1);
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v[i]=x;
        dp[x] = 0;
    }
    for(int i=1;i<=k;i++)
    {
        if(dp[i]==-1)
        {
           int ans=0;
           for(int j=0;j<n;j++)
           {
               if(i>v[j])
               {
                  ans|=dp[i-v[j]];
               }
           }
           dp[i] = !ans;
        }
    }
    if(!dp[k])
    cout<<"First";
    else
    cout<<"Second";
}
