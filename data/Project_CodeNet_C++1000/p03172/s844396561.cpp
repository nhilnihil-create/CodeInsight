#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define lld double
#define rep(i,a,b) for(ll i=a;i<=b;i++)
#define all(v) v.begin(),v.end()
#define vc vector
#define rep1(it,v) for(it=v.begin();it!=v.end();it++)
#define ayush ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define input(v) for(auto &it:v)cin>>it
#define M 1000000007
#define pb push_back

ll dp[105][100005]; 


int main()
{
    ll n,k; cin>>n>>k; vc<ll> v1(n); input(v1);
    
    rep(i,0,v1[0]) dp[0][i]=1; 
    
    rep(i,1,n-1)
    {
        vc<ll> v2(k+1); v2[0]=dp[i-1][0];
        rep(j,1,k) v2[j]=(v2[j-1] + dp[i-1][j])%M;
        rep(j,0,k)
        {
            if(j-v1[i] > 0)
            { ll a1=(v2[j]%M - v2[j-v1[i]-1]%M)%M; if(a1>=0) dp[i][j]=a1; else dp[i][j]=a1+M; }
            else 
            dp[i][j]=v2[j];
        }
    }
    
    cout<<dp[n-1][k];
    
}