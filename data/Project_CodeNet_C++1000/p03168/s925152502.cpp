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
#define inf 1000000007
#define pb push_back

lld v1[3005]; lld dp[3005][3005];

void fun(ll n)
{
    dp[0][0]=1; rep(i,1,n) dp[0][i]=0;
    rep(i,1,n) dp[i][0]=dp[i-1][0]*(1-v1[i-1]);
    rep(i,1,n)
    {
        rep(j,1,n)
        {
            dp[i][j]=dp[i-1][j-1]*v1[i-1]+dp[i-1][j]*(1-v1[i-1]);
        }
    }
    ll n1=(n/2)+1; lld ans1=0; cout<<setprecision(12);
    rep(i,n1,n) ans1+=dp[n][i];
    cout<<ans1<<endl;
}

int main()
{
    ll n; cin>>n; rep(i,0,n-1) cin>>v1[i];
    fun(n); 
    
    
}
