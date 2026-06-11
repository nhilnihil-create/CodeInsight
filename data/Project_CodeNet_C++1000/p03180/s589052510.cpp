/*
 _____ _             _              _           _ 
|_   _| |__   ___   / \   _ __  ___| |__  _   _| |
  | | | '_ \ / _ \ / _ \ | '_ \/ __| '_ \| | | | |
  | | | | | |  __// ___ \| | | \__ \ | | | |_| | |
  |_| |_| |_|\___/_/   \_\_| |_|___/_| |_|\__,_|_|                                                

*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
#define ll          long long
#define pb          push_back
#define ppb         pop_back
#define	endl		'\n'
#define mii         map<ll,ll>
#define msi         map<string,ll>
#define mis         map<ll, string>
#define rep(i,a,b)    for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=b-1;i>=a;i--)
#define trav(a, x) 	for(auto& a : x)
#define pii         pair<ll,ll>
#define vi          vector<ll>
#define vii         vector<pair<ll, ll>>
#define vs          vector<string>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll)x.size()
#define hell        1000000007
#define lbnd        lower_bound
#define ubnd        upper_bound
#define max(a,b)	(a>b?a:b)
#define min(a,b)	(a<b?a:b)

/*	For Debugging	*/
#define DEBUG 		cerr<<"\n>>>I'm Here<<<\n"<<endl;
#define display(x) trav(a,x) cout<<a<<" ";cout<<endl;
#define what_is(x)  cerr << #x << " is " << x << endl;

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
#define TIME        cerr << "\nTime elapsed: " << setprecision(5) <<1000.0 * clock() / CLOCKS_PER_SEC << "ms\n";
#define DECIMAL(n)  cout << fixed ; cout << setprecision(n);
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace __gnu_pbds;
using namespace std;
#define PI 3.141592653589793
#define N  100005
ll dp[16][1<<16];
ll stt[1<<16];
ll a[16][16];
ll n;
ll fun(ll mask)
{
	ll ans=0;
	rep(i,0,n)
	{
		if(!(mask&(1<<i)))
			continue;
		rep(j,i+1,n)
		{
			if(mask&(1<<j))
				ans+=a[i][j];
		}
	}
	return ans;
}
void solve()
{
	cin>>n;
	rep(i,0,n)
	{
		rep(j,0,n)
		cin>>a[i][j];
	}
	rep(i,1,1<<n)
	{
		stt[i]=fun(i);
		dp[n-1][i]=stt[i];
	}
	// what_is(stt[5]);
	repr(i,0,n-1)
	{
		rep(mask,0,(1<<n))
		{
			if(mask==0)
			{
				dp[i][mask]=stt[mask];
				continue;
			}
			for(ll k = mask; k > 0; k = (k-1) & mask)
			{
		    	dp[i][mask] = max(dp[i][mask],dp[i+1][k]+stt[(k^mask)]);
		    }
		}
	}
	// rep(i,0,n)
	// {
	// 	rep(j,0,(1<<n))
	// 	cout<<dp[i][j]<<" ";
	// 	cout<<endl;
	// }
	ll num=(1<<(n));
	// cout<<num<<endl;
	cout<<dp[0][num-1]<<endl;
	return;
}
int main()
{
	FAST
	int TESTS=1;
//	cin>>TESTS;
	while(TESTS--)
	{
		solve();
	}
	TIME
	return 0;
}