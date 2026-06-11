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
ll n;vl a;
ll dp[101][100001];
void solve()
{
    cin>>n;ll k;cin>>k;a.resize(n);forn(i,n)cin>>a[i];
    for(int i=0;i<=n;i++)for(int j=0;j<=k;j++)dp[i][j]=0;
    for(int i=0;i<=k;i++)dp[n][i]=1;
    for(int i=n-1;i>0;i--)
    {
        ll curr=0;
        for(int rem=0;rem<=k;rem++)
        {
            if(a[i]>=rem)curr=(curr+dp[i+1][rem])%mod;
            else
            {
                curr=(curr+(dp[i+1][rem]-dp[i+1][rem-a[i]-1]))%mod;
            }
            dp[i][rem]=curr;
        }
    }
    ll ans;
    if(a[0]==k)
    {
        ans=dp[1][k];
    }
    else
    {
        ans=(dp[1][k]-dp[1][k-a[0]-1]+mod)%mod;
    }
    cout<<ans<<endl;
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
