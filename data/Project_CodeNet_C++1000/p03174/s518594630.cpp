#include<bits/stdc++.h>
#include<math.h>
#define N 100005
#define K 200005
#define MOD (long long )1e9+7
#define ll long long int
using namespace std;
  vector<ll> dp(1<<21,-1);
bool c[21][21];
 int n;
void add_self(int &a,int b)
{
    a+=b;
    if(a>=MOD)
    {
        a-=MOD;
    }
}
void sub_self(int &a,int b)
{
    a-=b;
    if(a<0)
    {
        a+=MOD;
    }
}

ll min(ll a,ll b)
{
    return a<=b?a:b;
}
ll dfs(int mask,int a)
{
    if(dp[mask]!=-1)
    {
        return dp[mask];
    }
    if(mask==(1<<n) -1)
    {
       return 1;
    }
    if(a==n)
    {
        return 0;
    }
    int ans=0;
    for(int j=0;j<n;j++)
    {
        if(c[a][j] && !(mask&(1<<j)))
        {
            //cout<<-2<<endl;
            
            ans+=dfs(mask|(1<<j),a+1);
           if(ans>MOD)
           {
               ans-=MOD;
           }
        }
    }
    return dp[mask]=ans;
}
int main() {
   
    cin>>n;
  
  
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>c[i][j];
        }
    }
   
    ll ans =dfs(0,0);
    
    cout<<ans<<endl;
}
