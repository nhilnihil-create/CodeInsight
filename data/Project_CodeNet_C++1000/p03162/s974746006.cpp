#include<bits/stdc++.h>
#define lld         long long int
#define llf         long double
#define pb          push_back
#define mp          make_pair
#define IN          insert
#define loopN(n)    for(lld i=0;i<n;i++)
#define loop(p,n)   for(lld i=p;i<=n;i++)
#define rloop(p,n)  for(lld i=n;i>=p;i--)
#define loop2(p,n)  for(lld j=p;j<=n;j++)
#define all(v)      v.begin(),v.end()
#define F1          first
#define F2          second
#define INF         2e18
#define FILE        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
#define PI          2*acos(0.0)
#define ISO         ios::sync_with_stdio(false);cin.tie(0)
#define mem(a,b)    memset(a,b,sizeof(a))
#define case(z)     cout<<"Case "<<z<<": ";
using namespace std;
const lld mod=1e9+7;

lld on(lld m,lld p){return m | (1<<p);}
bool ison(lld m,lld p){return (bool)(m & (1<<p));}
lld flip(lld m,lld p){return m ^ (1<<p);}
lld allon(lld p){return (1<<p)-1;}
//______________________________________________________________________________________

lld n;
lld dp[100005][3];
lld a[100005][3];

lld fun(lld p, lld k)
{
    if(p>=n)return 0;
    if(dp[p][k]!=-1)
    {
        return dp[p][k];
    }
    lld ans=-INF;
    if(p==0)
    {
        loopN(3)
        {
            ans=max(ans,a[p][i]+fun(p+1,i));
        }
        return ans;
    }
    else
    {
        loopN(3)
        {
            if(i!=k)
            {
                ans=max(ans,a[p][i]+fun(p+1,i));
            }

        }

    }
    return dp[p][k]=ans;



}


int main()
{
    ISO;

    //lld t;cin>>t;while(t--)
    mem(dp,-1);
    cin>>n;
    loopN(n)loop2(0,2)cin>>a[i][j];
    cout<<fun(0,0)<<endl;


    return 0;
}


