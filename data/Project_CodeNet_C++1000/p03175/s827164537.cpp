/**
 *COYG, 14 FA Cups we are back baby
 */
#include <bits/stdc++.h>
using namespace std;
#define mod 		1000000007
#define ll 		long long
#define mp 		make_pair
#define pb 		push_back
#define forn(i,n) 	for(int i=0;i<n;i++)
#define for1(i,n) 	for(int i=1;i<n;i++)
#define ford(i,n) 	for(int i=n-1;i>=0;i--)
#define vi 		vector<int>
#define vl 		vector<ll>
#define pii 		pair<int,int>
#define pll 		pair<ll,ll>
#define vpi 		vector<pair<int,int> >
#define vpl		vector<pair<ll,ll> >
#define vvi 		vector<vector<int> >
#define vvl 		vector<vector<ll> >
#define ull 		unsigned long long
#define IOS 		ios_base::sync_with_stdio(false);
#define PI 		3.1415926535897932384626
#define ff 		first
#define ss 		second
#define char2Int(c) 	(c-'0')
#define FOREACH(i,t) 	for (auto i=t.begin(); i!=t.end(); i++)
#define clr(a,x) 	memset(a,x,sizeof(a)) //set elements of array to some value
#define all(x)		(x).begin(),(x).end()//cout<<"Case #"<<zzz<<": ";
#define plll pair<ll,pll >
ll n;vvi adj;pll dp[1+(int)1e5];
pll getans(int x,int parent)
{
    if(dp[x].ff!=-1)return dp[x];
    pll ans=mp(1,1);
    forn(i,adj[x].size())
    {
        if(adj[x][i]==parent)continue;
        pll child=getans(adj[x][i],x);
        ans.ff=(ans.ff*((child.ff+child.ss)%mod))%mod;
        ans.ss=(ans.ss*child.ff)%mod;
    }
    dp[x]=ans;
    return ans;
}
void solve()
{
    cin>>n;adj.resize(n+1);forn(i,n+1)adj[i].clear();
    forn(i,n-1){int x,y;cin>>x>>y;adj[x].pb(y);adj[y].pb(x);}
    forn(i,n+1)dp[i]=mp(-1,-1);
    pll ans=getans(1,-1);
    cout<<(ans.ff+ans.ss)%mod<<endl;
}
int main()
{
    IOS;cin.tie(NULL);
    ll zz;zz=1;
    //cin>>zz;
    for(int zzz=1;zzz<=zz;zzz++)
    {
        solve();
    }
    return 0;
}
