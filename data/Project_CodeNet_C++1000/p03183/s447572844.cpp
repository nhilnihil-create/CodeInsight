#pragma GCC optimize ("-O3")
#include <bits/stdc++.h>  
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<ll> v32;
typedef vector<vector<ll> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 1e9+7;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 1e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
struct block
{
	int w,s,v,idx;
};
bool cmp(block &a, block &b)
{
	return p64(a.s+a.w,a.idx) < p64(b.s+b.w,b.idx);
}
int MAX=3e4;
void solve()
{
	int n;
	cin>>n;
	vector<block> arr(n+1);
	for (int i=1; i<=n; i++)
	{	
		cin>>arr[i].w>>arr[i].s>>arr[i].v;
		arr[i].idx=i;
	}
	sort(arr.begin()+1,arr.end(),cmp);
	vv64 dp(n+1,v64(MAX+100,-INF));
	dp[0][0]=0;
	for (int i=1; i<=n; i++)
	{
		dp[i][0]=0;
		for (int j=1; j<=MAX; j++)
		{
			dp[i][j]=dp[i-1][j];
			if (j>=arr[i].w && j-arr[i].w <= arr[i].s) 
			{
				dp[i][j]=max(dp[i][j],dp[i-1][j-arr[i].w]+arr[i].v);
			}
		}
	}
	ll ans=0;
	for (int i=0; i<=MAX; i++)
	{
		ans=max(ans,dp[n][i]);
	}
	cout<<ans<<endl;
}
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t=1;
    while (t--)
    {
        solve();
    }
    return 0;   
} 