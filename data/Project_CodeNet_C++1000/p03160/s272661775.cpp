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


const int INF = 1e9+5;
int main()
{
	ll n;
	cin>>n;
	vector <ll> v(n);
	for(auto &i : v)
		cin>>i;

	vector <ll> dp(n,INF);
	dp[0] = 0;
	
	for(int i=0;i<n;++i)
	{
		for(int j : {i+1 , i+2})
		{
			if(j<n)
			{
				dp[j] = min(dp[j] , dp[i]+abs(v[i]-v[j]));
			}
		}
	}
	cout<<dp[n-1]<<endl;
	return 0;

}