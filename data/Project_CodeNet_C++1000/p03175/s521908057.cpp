#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
vector<list<int>> v(100005);
vector<vector<ll>> dp(100005,vector<ll>(2));
vector<int>par(100005);
int n;
ll solve(int i,int pclr)
{
    if(dp[i][pclr])
    return dp[i][pclr];
    ll res=1,ans=0;
    for(auto x:v[i])
    {
        if(par[i]!=x){
        par[x]=i;
        res = (res%mod*solve(x,1)%mod)%mod;
        }
    }
    if(pclr){
        ans = 1;
        for(auto x:v[i])
        {
            if(par[i]!=x){
                par[x]=i;
             ans = (ans%mod*solve(x,0)%mod)%mod;
            }
        }
    }
    return dp[i][pclr]=(res%mod+ans%mod)%mod;
}
int main() {
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cout<<solve(1,1)%mod;
}
