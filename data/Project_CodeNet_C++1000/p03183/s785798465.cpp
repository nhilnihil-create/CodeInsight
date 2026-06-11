#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define endl '\n'
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define pi acos(-1)
#define line cout<<"----------------------------"<<endl
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define filein freopen("input.text","r",stdin)
#define fileout freopen("output.txt","w",stdout)
using namespace std;
const ll mx=20009;	
struct edge
{
	ll w,s,val; 
};
vector<edge> v; 
bool cmp(edge a,edge b)
{
 	return a.w+a.s<b.w+b.s; 
}
ll dp[mx];  ///maximum value when total weight  is i
int main()
{	
	ll n; 
	cin>>n; 
	for(ll i=0;i<n;i++)
	{
		ll a,b,c; 
		cin>>a>>b>>c; 
		v.pb({a,b,c});
	}
	sort(v.begin(),v.end(),cmp);
	for(auto x:  v)
	{
		for(ll used=x.s;used>=0;used--)
		{
			dp[used+x.w]=max(dp[used+x.w],dp[used]+x.val);
		}
	}
	ll ans=0; 
	for(ll i=0;i<mx;i++) ans=max(ans,dp[i]);
	cout<<ans<<endl; 
}
