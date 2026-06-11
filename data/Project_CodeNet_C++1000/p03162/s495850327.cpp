#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(NULL); 
#define fi first
#define se second
#define mp make_pair
#define pi 3.14159265359
#define MOD 1000000007
typedef long long ll;
#define mp make_pair
#define ALL(v) v.begin(), v.end() 
#define F(i,s,n) for(i=s;i<n;++i)
#define pb push_back
#define tin freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define pll pair<ll,ll>
ll max(ll a,ll b)
{
    return a*(a>=b)+b*(b>a);
}
/*----------------------------------------------------------*/
ll n;vector<vector<ll>>a;
map<pll,ll>dp;
ll fun(ll n,ll pre)
{
    if(n==-1)return 0;
    if(dp.count(mp(n,pre)))return dp[mp(n,pre)];
    ll p=-1;
    for(ll i=0;i<3;++i)
    {
        if(i==pre)continue;
        p=max(p,a[n][i]+fun(n-1,i));
    }
    return dp[mp(n,pre)]=p;
}
void solve()
{
    cin>>n;a.resize(n,vector<ll>(3));
    for(ll i=0;i<n;++i)
    {
        for(ll j=0;j<3;++j)cin>>a[i][j];
    }
    cout<<fun(n-1,-1);
}

int main()
{
    //tin
    fast
    ll tc=1;//cin>>tc;
   for(ll i=1;i<=tc;++i)
   {
    //cout<<"Case #"<<i<<": ";
    solve();
    if(i!=tc)cout<<"\n";
   }
return 0;
}
//End-Cases
//Precomputation
//Segmentation Fault
//Complexity
//Break it up
//Sub Problems
