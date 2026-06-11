#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
#define ll 		 long long int
#define rep(i,n) for(int i=0;i<n;i++)
#define mod 	 1000000007
#define MOD      998244353
#define mp       make_pair
#define pb       push_back
#define F        first
#define S        second
#define t()      ll test;cin>>test;while(test--)
#define ii       pair<int,int>
#define endl     "\n"
#define que_max  priority_queue <int>
#define IOS      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef tree < int ,  null_type ,  greater <int> ,  rb_tree_tag ,  tree_order_statistics_node_update > pbds;

int pw(int b, int p) { int r = 1; while (p > 0) { if (p & 1) r = r * b;
        p = p >> 1; b = b * b; } return r; }


ll n;
vector <ll> arr(1e5);
vector <ll> dp(1e5 , -1);

ll solve(ll id)
{
	if(id == n-1)
		return 0;

	if(dp[id]!=-1)
	{
		return dp[id];
	}
	ll ans = abs(arr[id+1]-arr[id]) + solve(id+1);

	if(id+2<n)
	{
		ans = min(ans , abs(arr[id+2]-arr[id]) + solve(id+2));
	}
		return dp[id] = ans;
}
int main()
{
	cin>>n;

	arr.resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<solve(0)<<endl;
}
