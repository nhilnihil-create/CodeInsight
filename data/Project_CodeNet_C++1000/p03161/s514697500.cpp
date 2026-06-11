#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll N,K;
    cin>>N>>K;
    ll h[N];
    for(ll i=0;i<N;i++)
    {
        cin>>h[i];
    }
    ll dp[N];
    dp[0]=0;
    for(ll i=1;i<N;i++)
    {
        ll temp=i-1;
        ll minm=abs(h[i]-h[i-1])+dp[i-1];
        while(temp>=0 && i-temp<=K)
        {
            minm=min(abs(h[i]-h[temp])+dp[temp],minm);
            temp--;
        }
        dp[i]=minm;
    }
    cout<<dp[N-1];
}