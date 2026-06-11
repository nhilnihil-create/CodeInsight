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
#define N  3005
ll dp[N][N];
ll n;
string s;
void solve()
{
	cin>>n;
	cin>>s;
	dp[1][1]=1;
	rep(len,2,n+1)
	{
		rep(i,1,len+1)
		{
			if(s[len-2]=='<')
			{
				dp[len][i]=(dp[len][i]+dp[len-1][i-1])%hell;
			}
			else
			{
				dp[len][i]=(dp[len][i]+dp[len-1][len-1]-dp[len-1][i-1]+hell)%hell;	
			}
		}
		// rep(i,1,len+1)
		// cout<<dp[len][i]<<" ";
		// cout<<endl;
		rep(i,1,len+1)
		dp[len][i]=(dp[len][i-1]+dp[len][i])%hell;
	}
	cout<<dp[n][n]<<endl;
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