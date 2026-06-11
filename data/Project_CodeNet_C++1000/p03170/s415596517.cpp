#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,k;
    cin>>n>>k;
    ll a[n];
    for(ll i=0;i<n;i++) cin>>a[i];
    ll dp[k+1]={0};
    for(ll i=1;i<=k;i++)
    {
        for(ll j=0;j<n;j++)
        {
            if(i>=a[j] && dp[i-a[j]]==0)
            {
                dp[i]=1;
                break;

            }
        }
    }
    if(dp[k]) cout<<"First";
    else cout<<"Second";
}
