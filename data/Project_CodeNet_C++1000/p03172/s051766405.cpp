/*       _________
        /|______/ \
        ||  _|_|\  |
        || |_|   | /
        ||    _ / |
        ||  _| \\  \    
        ||_|_|\ || |
        |/_|/ | /|_/
              /__/      Written by: Rishabh Roshan
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int            	long long
#define integer        	int32_t
#define mod         	1000000007
#define vint        	vector<int>
#define pint        	pair<int, int>
#define umint        	unordered_map<int, int>
#define mint        	map<integer, integer>
#define in(x)        	int x; cin>>x
#define setbits(x)    	__builtin_popcountll(x)
#define zerobits(x)    	__builtin_ctzll(x)
#define w(x)        	int x; cin>>x; while(x--)
#define sp(x, y)    	fixed<<setprecision(y)<<x
#define poll(x)        	x.front(); x.pop()
#define f(x)        	for(int i=0; i<x; i++)
#define fj(x)			for(int j=0; j<x; j++)
#define fn(n, x)			for(int i=n; i<x; i++)
#define endl         	'\n'
#define inf         	1e9 
#define order_set     	tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;

// #include "functions.h"

void om_shree_ganeshaya_namah(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

vector<vint> dp;

void print(vector<vint> arr){
	f(arr.size()){
		fj(arr[i].size()) cout<<arr[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}

int32_t main() {

    om_shree_ganeshaya_namah();

    in(n); in(k);
    vint arr(n);
    f(n) cin>>arr[i];
    sort(arr.begin(), arr.end());

    dp = vector<vint>(n, vint(k+1));

    dp[0][0] = 1;
    fn(1, k+1){
    	if(i>arr[0]){
    		dp[0][i] = dp[0][i-1];
    		continue;
    	}
    	dp[0][i]=(dp[0][i-1]+1)%mod;
    }

    for(int i=1; i<n-1; i++){
    	dp[i][0] =1;
    	for(int j=1; j<=k; j++){
    		int ans=0, index = j-min(arr[i], j);
    		if(index==0)
    			ans = dp[i-1][j];
    		else
    			ans = (dp[i-1][j]-dp[i-1][index-1])%mod;
    		if(ans<0)
    			ans+=mod;
    		dp[i][j] = (ans+dp[i][j-1])%mod;
    	}
    }

    int ans=0, index = k-min(arr[n-1], k);
    if(n!=1)
    	if(index==0)
    		ans = dp[n-2][k];
    	else
    		ans = (dp[n-2][k]-dp[n-2][index-1])%mod;
    else
    	if(k==0)
    		ans = dp[n-1][k];
    	else
    		ans = (dp[n-1][k]-dp[n-1][k-1])%mod;

    if(ans<0)
    	ans+=mod;

    cout<<ans;
}