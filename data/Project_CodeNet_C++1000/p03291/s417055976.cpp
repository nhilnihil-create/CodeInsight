///Bismillahir Rahmanir Rahim
#include "bits/stdc++.h"

#define                           ll                          long long
#define                           int                         ll
#define                           fi                          first
#define                           si                          second
#define                           mp                          make_pair
#define                           pb                          push_back
#define                           pi                          pair<ll,ll>
#define                           clr(x)                      memset(x,0,sizeof(x));
#define                           f(i,l,r)                    for(int i=l;i<=r;i++)
#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)
#define                           done(i)                     cout<<"done = "<<i<<endl;
#define                           show(x,y)                   cout<<x<<" : ";for(auto z:y)cout<<z<<" ";cout<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

const ll inf=1e18;
const int mod=1e9+7;
const int M=100005;
inline ll bigmod(ll B,ll P){ll R=1;while(P>0){if(P&1){R=(R*B)%mod;}P>>=1;B=(B*B)%mod;}return R;}
inline ll ad(ll x,ll y){ll ret=(x%mod+y%mod)%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
inline ll sub(ll x,ll y){ll ret=((x%mod)-(y%mod)+mod)%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
inline ll gun(ll x,ll y){ll ret=((x%mod)*(y%mod))%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
int dp[M][4];
int a[M];
 main()

{
    fast
    dp[0][0]=1;
    string s;
    cin>>s;
    int n=s.size();
    f(i,0,n-1)
    {
        if(s[i]=='?')a[i+1]=3;
        else a[i+1]=s[i]-'A';
    }
    f(i,1,n)
    {
        if(a[i]==3)
        {
            f(j,0,3)
            {
                dp[i][j]=ad(dp[i][j],gun(3,dp[i-1][j]));
            }
        }
        else
        {
             f(j,0,3)
             {
                 dp[i][j]=ad(dp[i][j],dp[i-1][j]);
             }
        }
        if(a[i]==0 || a[i]==3)dp[i][1]=ad(dp[i][1],dp[i-1][0]);
        if(a[i]==1 || a[i]==3)dp[i][2]=ad(dp[i][2],dp[i-1][1]);
        if(a[i]==2 || a[i]==3)dp[i][3]=ad(dp[i][3],dp[i-1][2]);

    }
    cout<<dp[n][3]<<endl;
    return 0;

}


































