/**
 *COYG, 14 FA Cups we are back baby
 */
#include <bits/stdc++.h>
using namespace std;
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
const int mod=1e9+7;
void solve()
{
    ll n;cin>>n;string s;cin>>s;
    vector<ll> dp(1,0);ll sz=2;dp.pb(1);dp.pb(1);
    for(int i=(int)s.size()-1;i>=0;--i,++sz)
    {
        vector<ll> curr;curr.pb(0);ll sum=0;
        for(int which=1;which<=sz;which++)
        {
            if(s[i]=='>')
            {
                sum=(sum+dp[which-1])%mod;
            }
            else
            {
                ll toadd=(dp[sz]-dp[which-1]+mod)%mod;
                sum=(sum+toadd)%mod;
            }
            curr.pb(sum);
        }
        curr.pb(sum);
        dp=curr;
    }
    cout<<dp[(int)dp.size()-1]<<endl;
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
