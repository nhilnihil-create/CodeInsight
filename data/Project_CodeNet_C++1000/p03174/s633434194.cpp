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
ll n;int a[22][22];
ll dp[21][(1<<21)+1];
ll getans(ll m,ll f)
{
    if(m>=n)return 1;
    if(dp[m][f]!=-1)return dp[m][f];
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        if(!(f&(1<<i))&&a[m][i]==1)
        {
            ans=(ans+getans(m+1,f|(1<<i)))%mod;
        }
    }
    dp[m][f]=ans;
    return ans;
}
void solve()
{
    cin>>n;
    forn(i,n)forn(j,n)cin>>a[i][j];
    forn(i,n)forn(j,1<<n)dp[i][j]=-1;
    cout<<getans(0,0)<<endl;
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
