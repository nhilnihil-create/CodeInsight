/************
* 	@Just Another Source code by: ankit.sangwan1999
*	@created on: 4 Sept 2020
*/
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL) //;cout.tie(NULL)
#define ll long long
const int mod = 1e9+7;
const long double pie = 3.14159265358979323846;
#define endl '\n'
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
gp_hash_table<int, ll> ma; // orderd_map using pb_ds
const int N = 401;
ll dp[N][N];
ll pre[N];
ll fun(int i, int j, int* arr){
	if(i==j) return 0;
	if(dp[i][j] != -1) return dp[i][j];

	ll ans = LLONG_MAX;
	for(int k=i;k<=j-1;k++){
		ll curr_cost = pre[j+1] - pre[i];
		ans = min(ans, curr_cost + fun(i, k, arr) + fun(k+1, j, arr));
	}
	return dp[i][j] = ans;
}

void solve(){
	memset(dp, -1, sizeof(dp));
	int n; cin>>n;
	int arr[n]; for(int i=0;i<n;i++) cin>>arr[i];
	pre[0] = 0;
	for(int i=1;i<=n;i++){
		pre[i] = pre[i-1] + arr[i-1];
	}
	cout<<fun(0, n-1, arr);
}
signed main(){
	// #ifndef ONLINE_JUDGE
 //    freopen("/mnt/DATA/D_Drive/CP/input.txt", "r", stdin);
 //    freopen("/mnt/DATA/D_Drive/CP/output.txt", "w", stdout);
 //    #endif

    fastio;
    int t=1;
    //cin>>t;

    while(--t>=0){
    	solve();
    }
		

    return 0;
}