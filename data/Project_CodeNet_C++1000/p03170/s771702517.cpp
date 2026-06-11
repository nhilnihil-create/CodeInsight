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
int n;int dp[100001];int a[100001];
int getans(int curr)
{
    if(dp[curr]!=-1)return dp[curr];
    int flag=0;
    forn(i,n)
    {
        if(a[i]<=curr)
        {
            if(getans(curr-a[i])==0)flag=1;
        }
    }
    dp[curr]=flag;
    return flag;
}
void solve()
{
    cin>>n;int k;cin>>k;forn(i,n)cin>>a[i];
    forn(i,k+1)dp[i]=-1;dp[0]=0;
    if(getans(k))cout<<"First";
    else cout<<"Second";
    cout<<endl;
}
int main()
{
    IOS;cin.tie(NULL);
    int zz;zz=1;
    //cin>>zz;
    for(int zzz=1;zzz<=zz;zzz++)
    {
        solve();
    }
    return 0;
}
