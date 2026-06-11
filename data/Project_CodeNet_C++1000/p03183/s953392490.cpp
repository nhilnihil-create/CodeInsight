/*input
5
1 10000 1000000000
1 10000 1000000000
1 10000 1000000000
1 10000 1000000000
1 10000 1000000000

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
#define N  1005
lld dp[N][20*N];
void inii(){
	rep(i,0,N){
		rep(j,0,20*N){
			dp[i][j]=-1;
		}
	}
}
vector <pair<pii,lld>> V;
lld n;
lld func(lld pos,lld weight){
	if(weight<0){
		return -1e18;
	}
	if(pos==n){
		return 0;
	}
	if(dp[pos][weight]!=-1){
		return dp[pos][weight];
	}
	lld ans=0;	
	ans=max(ans,func(pos+1,weight));
	ans=max(ans,V[pos].S+func(pos+1,min(weight-V[pos].F.F,V[pos].F.S)));
	dp[pos][weight]=ans;
	return ans;
}
void solve()
{
	inii();
	cin >> n;
	V.resize(n);

	rep(i,0,n){
		cin >> V[i].F.F >> V[i].F.S >> V[i].S;
	}
	auto cmp = [&] (pair<pii,lld> x,pair<pii,lld> y){
		return (x.F.S+x.F.F) > (y.F.S+y.F.F);
	};

	sort(all(V),cmp);
	cout << func(0,20000) << endl;
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