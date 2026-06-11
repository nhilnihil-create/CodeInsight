#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define flash ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lb lower_bound
#define ub upper_bound
#define endl '\n'
ll a[23][23];
ll dp[10000000]={0};
int main()
{
    flash
    ll n;cin>>n;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    ll x=1<<n;
    dp[0]=1;
    for(ll i=0;i<x-1;i++)
    {
        ll copy=i;ll mandone=0;
        while(copy>0)
        {
          ll d=copy%2;if(d==1)mandone++;
          copy/=2;  
        }
        for(ll k=0;k<n;k++)
            {
                ll fat=(1<<k)&i;
                if((a[mandone][k]==1)&&(fat==0))
                {
                
                ll iu=i+(1<<k);ll top=1e9+7;
                dp[iu]=(dp[iu]+dp[i])%top;
                }
            }
        
    }
    cout<<dp[(1<<n)-1]<<endl;
}