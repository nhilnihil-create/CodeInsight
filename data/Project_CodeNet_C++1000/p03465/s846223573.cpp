#include<bits/stdc++.h>
#include<string>
#define rep(i,a,b) for(long long int i=(a);i<(b);i++)
#define se(a) a.begin(),a.end()
#define ll long long int
#define mll map<ll,ll>
#define pll pair<ll, ll>
#define pii pair<int,int>
#define pb push_back
#define mk make_pair
#define F first
#define S second
#define mod 1000000007
#define maxn 100005
#define inf 1e16
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int main()
{
//	ll tc;
//	cin>>tc;
//	while(tc--)
	{
		ll n;
		cin>>n;
		ll a[n];
		rep(i,0,n)
		cin>>a[i];
		ll sum=0;
		rep(i,0,n)
		sum+=a[i];
		bitset<4000005> dp;
		dp.set(0);
		
		for(int i=0;i<n;i++)
		dp=dp|dp<<a[i];
		ll x=(sum+1)/2;
		while(dp[x]==0)
		x++;
		cout<<x<<endl;
	}
}