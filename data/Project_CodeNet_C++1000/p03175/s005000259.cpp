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

vector<vint> dp;
unordered_map<int, vint> dict;

pint dfs(int node, int parent){

	int white=1, black = 1;
	for(auto i:dict[node]){
		if(i==parent)
			continue;
		
		pint p = dfs(i, node);
		black*=p.first;
		white*=(p.first+p.second);

		black%=mod; white%=mod;
	}
	return make_pair(white, black);
}

int32_t main() {

    om_shree_ganeshaya_namah();

    in(n);
    dp = vector<vint>(n+1, vint(2));
    f(n-1){
    	in(u); in(v);
    	dict[u].push_back(v);
    	dict[v].push_back(u);
    }

	pint p = dfs(1, 0);
	int ans = (p.first+p.second)%mod;
	cout<<ans;    

}