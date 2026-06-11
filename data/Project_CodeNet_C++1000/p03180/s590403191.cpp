/*input
16
0 5 -4 -5 -8 -4 7 2 -4 0 7 0 2 -3 7 7
5 0 8 -9 3 5 2 -7 2 -7 0 -1 -4 1 -1 9
-4 8 0 -9 8 9 3 1 4 9 6 6 -6 1 8 9
-5 -9 -9 0 -7 6 4 -1 9 -3 -5 0 1 2 -4 1
-8 3 8 -7 0 -5 -9 9 1 -9 -6 -3 -8 3 4 3
-4 5 9 6 -5 0 -6 1 -2 2 0 -5 -2 3 1 2
7 2 3 4 -9 -6 0 -2 -2 -9 -3 9 -2 9 2 -5
2 -7 1 -1 9 1 -2 0 -6 0 -6 6 4 -1 -7 8
-4 2 4 9 1 -2 -2 -6 0 8 -6 -2 -4 8 7 7
0 -7 9 -3 -9 2 -9 0 8 0 0 1 -3 3 -6 -6
7 0 6 -5 -6 0 -3 -6 -6 0 0 5 7 -1 -5 3
0 -1 6 0 -3 -5 9 6 -2 1 5 0 -2 7 -8 0
2 -4 -6 1 -8 -2 -2 4 -4 -3 7 -2 0 -9 7 1
-3 1 1 2 3 3 9 -1 8 3 -1 7 -9 0 -6 -8
7 -1 8 -4 4 1 2 -7 7 -6 -5 -8 7 -6 0 -9
7 9 9 1 3 2 -5 8 7 -6 3 0 1 -8 -9 0
*/
/*

**************************
*						 *
* AUTHOR :: shado_w      *
*						 *
**************************

*/
#include<bits/stdc++.h>
#define lld          long long int
#define pb          push_back
#define ppb         pop_back
#define	endl		'\n'
#define mii         map<lld,lld>
#define msi         map<string,lld>
#define mis         map<lld, string>
#define mpi         map<pair<lld ,lld >,lld >
#define pii         pair<lld,lld>
#define vi          vector<lld>
#define vpi 		vector<pii>
#define vs          vector<string>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (lld)x.size()
#define hell        1000000007
#define rrep(i,m,n)	for(lld i=m;i>=n;i--)
#define rep(i,m,n)	for(lld i=m;i<n;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define what_is(x)  cerr << #x << " is " << x << endl;
#define pr(x) 		cout<< x << " ";
#define pre(x)		cout<< x << endl ;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>; 
//change null_type to get ordered_map
#define N  16
lld ans[1<<N];
lld dp[1<<N];
lld a[N][N];
void solve()
{
	lld n;
	cin >> n;
	rep(i,0,n){
		rep(j,0,n){
			cin >> a[i][j];
		}
	}
	rep(i,0,1<<n){
		lld cnt=0;
		rep(j,0,n){
			rep(k,j+1,n){
				if((i>>j)&1 && (i>>k)&1){
					cnt+=a[j][k];
				}
			}
		}
		ans[i]=cnt;
	}

	rep(i,0,1<<n){
		dp[i]=ans[i];
		for(int j=i;j>0;j=(j-1)&i){
			dp[i]=max(dp[i],dp[j]+ans[j^i]);
		}
	}
	cout << dp[(1<<n)-1] << endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tests=1;
	//cin>>tests;
	while(tests--)
	{
		solve();
	}
}