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
void solve()
{
    ll n;cin>>n;vl a(n);vl h(n);
    forn(i,n)cin>>h[i];
    forn(i,n)cin>>a[i];
    ll base=1;
    while(base<=n)
    {
        base*=(ll)2;
    }
    vl tree(2*base);
    vl dp(n);
    for(int i=0;i<n;i++)
    {
        ll currans=0;
        ll ptr=base+h[i];
        while(ptr>1)
        {
            if(ptr&1)
                currans=max(currans,a[i]+tree[ptr-1]);
            ptr/=2;
        }
        dp[i]=currans;
        ptr=base+h[i];
        while(ptr>1)
        {
            tree[ptr]=max(tree[ptr],currans);
            ptr/=2;
        }
    }
    ll ans=0;
    forn(i,n)ans=max(ans,dp[i]);
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
