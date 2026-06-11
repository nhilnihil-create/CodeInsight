#include<bits/stdc++.h>
typedef  long long int ll;
typedef  long double ld;
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL) 
#define input(arr,n) for(ll i1=0;i1<n;i1++ )cin>>arr[i1]
#define mod 1000000007
#define F first
#define S second 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3")
//recursions\
#pragma comment(linker, "/stack:200000000")
//loops\
#pragma GCC optimize("unroll-loops")
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>//s.order_of_key(val) *s.find_by_order(ind)
using namespace std;
const int N = 1e5+5;
vector<ll> v[N];
ll dp[N][2];//black - white
void dfs(ll idx, ll par)
{
	dp[idx][0] = dp[idx][1] = 1;
	for(ll i = 0; i < v[idx].size(); i++)
	{
		ll child = v[idx][i];
		if(child != par)
		{
			dfs(child, idx);
			dp[idx][0] = dp[idx][0] * (dp[child][0] + dp[child][1]) % mod;
			dp[idx][1] = dp[idx][1] * dp[child][0] % mod;
		}
	}
}
int main()
{
	sync;
	ll n;
	cin >> n;
	for(ll i = 0; i < n - 1; i++)
	{
		ll x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1, 0);
	cout << (dp[1][0] + dp[1][1]) % mod;
}
	