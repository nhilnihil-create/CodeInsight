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
ll n;vl a;vl pre;
ll dp[401][401];
ll getans(ll l,ll r)
{
    if(l>=r)return 0;
    if(dp[l][r]!=-1)return dp[l][r];
    ll ans=LLONG_MAX;
    for(int i=l;i<r;i++)
    {
        ans=min(ans,pre[r+1]-pre[l]+getans(l,i)+getans(i+1,r));
    }
    dp[l][r]=ans;
    return ans;
}
void solve()
{
    cin>>n;a.resize(n);forn(i,n)cin>>a[i];pre.clear();pre.pb(0);
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];pre.pb(sum);
    }
    for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)dp[i][j]=-1;
    cout<<getans(0,n-1)<<endl;
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
