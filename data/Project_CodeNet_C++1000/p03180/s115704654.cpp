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
#include<time.h>
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
#define fn(n, x)		for(int i=n; i<x; i++)
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

int32_t main() {

    om_shree_ganeshaya_namah();

    in(n);
    vint dp(1<<n), pre(1<<n);
    vector<vint> arr(n, vint(n));
    f(n) fj(n) cin>>arr[i][j];

    for(int i=0; i<(1<<n); i++){
    	int sum=0;
    	for(int j=0; j<n; j++){
    		if(i&(1<<j)){
    			for(int k=j+1; k<n; k++){
    				if(i&(1<<k))
    					sum+=arr[j][k];
    			}
    		}
    	}
    	pre[i] = sum;
    }

    for(int i=0; i<(1<<n); i++){
    	vint pos;	//position not selected yet...
    	fj(n)  if(!(i&(1<<j))) pos.push_back(j);

    	int size = pos.size();
    	for(int j=0; j<(1<<size); j++){
    		int mask=0;
    		for(int k=0; k<size; k++){
    			if(j&(1<<k))
    				mask|=(1<<pos[k]);
    		}
    		dp[mask|i] = max(dp[mask|i], pre[mask]+dp[i]);	
    	}
    }

    cout<<dp[(1<<n)-1];
}