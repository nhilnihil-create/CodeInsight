/* Press F to pay respects */
#define _CRT_SECURE_NO_DEPRECATE
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds; 
using namespace std;
#define int long long int
#define SYNC std::ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define FRE freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
typedef long double ld;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii>   vii;
//typedef tree<int, null_type, less<int>, rb_tree_tag, 
//             tree_order_statistics_node_update> 
//    data_set;
#define rep(i,l,r)   for(int i=(l);i<(r);i++)
#define deb(x)     cout << (#x) << " is " << (x) << endl
#define dbg(x)     cout << x << ' '
#define here cout << " Hey baitch!!\n";
#define  pb push_back
#define  F  first
#define  S  second
#define all(v) (v).begin(),(v).end()
#define sz(a) (int)((a).size())
#define sq(x) ((x)*(x))
const int MOD = 1e9+7;
const int MOD1 = 998244353;
const int N = 2e5+5;
const int INF = 200;
const ld PI = 3.1415926535898;
void add(int &a, int b) {
	a += b;
	if(a >= MOD)	
		a -= MOD;
	if(a < 0)
		a += MOD;
}
bool comp(int x, int y) {
	if(__builtin_popcountll(x) == __builtin_popcountll(y))	return x < y;
	return __builtin_popcountll(x) < __builtin_popcountll(y);
}
int dp[16][(1LL<<16)];
int32_t main()
{
	SYNC
	int n; cin >> n;
	int a[100][100];
	memset(a,0,sizeof a);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	int mx_len = (1LL<<n);
	vi dp(mx_len,0);
	vi v;
	rep(i,0,mx_len)	v.pb(i);
	sort(all(v),comp);
	auto cost_merge = [&] (int group, int node) -> int 
	{
		int cost = 0;
		for(int i = 0; i < n; i++) {
			if((1LL<<i)&group) {
				cost += a[i][node];
			}
		}
		return cost;
	};
	for(int mask : v)
	{
		for(int nv = 0; nv < n; nv++) {
			if(!((1LL<<nv)&mask)) {
				int new_mask = mask|(1LL<<nv);
				dp[new_mask] = dp[mask] + cost_merge(mask, nv);
			}
		}
	}
	for(int mask : v) {
		for(int i = mask; i >= 1; i = (i-1)&mask)
		{
			dp[mask] = max(dp[mask],dp[i]+dp[mask^i]);
		}
	}
	cout << dp[mx_len-1];
    return 0;
}