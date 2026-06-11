#pragma GCC optimize("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define e1 first
#define e2 second
#define int int_fast32_t
#define uint uint_fast64_t
#define ll int_fast64_t
#define ull uint_fast64_t
#define int16 int_fast16_t
#define uint16 uint_fast16_t
#define int32 int_fast32_t
#define uint32 uint_fast32_t
#define int64 int_fast64_t
#define uint64 uint_fast64_t
#define ld long double
#define float long double
#define size(x) (int)x.size()
#define satori int testCases; cin>>testCases; while(testCases--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define all(r) begin(r),end(r)
#define rall(r) rbegin(r),rend(r)
#define time chrono::high_resolution_clock().now().time_since_epoch().count()
#define elapsed(__begin,__end) (__end-__begin)/CLOCKS_PER_SEC
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
float pi=3.14159265358979323846;

const int MAXN=4e2+10;
const ll inf=1e18+2137;

ll dp[MAXN][MAXN],w[MAXN][MAXN];

int32_t main()
{
	fastio;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>w[i][i];
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			w[i][j]=w[i][j-1]+w[j][j];
	for(int l=2;l<=n;l++)
		for(int i=1;i+l-1<=n;i++)
		{
			dp[i][i+l-1]=inf;
			for(int m=i;m<i+l-1;m++)
				dp[i][i+l-1]=min(dp[i][i+l-1],dp[i][m]+dp[m+1][i+l-1]+w[i][m]+w[m+1][i+l-1]);			
		}
	cout<<dp[1][n]<<'\n';
}