/********   All Required Header Files ********/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;
// ****  All Required define Pre-Processors and typedef Constants *******/
#define mem(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define fl(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

#define fi(it, l) for (auto it = l.begin(); it != l.end(); it++)

#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
const double pi=acos(-1.0);
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> dmap;
typedef set<int> dset;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
/********** solver function **********/
int dfs(int u, vector<vector<int>>&g, vector<int> &dp,int p=-1){
    // if( )
    // visited[u]=true;
    if( dp[u]!=-1) return dp[u];
    int ans=0;
    for( int i=0;i<g[u].size();i++){
        if( g[u][i]!=p){
            // cout<<" ans"<<ans<<"|";
            ans=max(ans,1+dfs( g[u][i], g,dp,u));
        }
    }
	return dp[u]= ans;
}
/********** Main()  function **********/
int main()
{std::ios::sync_with_stdio(false);
	int n,m;
    cin>>n>>m;
    // vector<bool> visited(n, false);
    vector<int> dp(n+1,-1);
    vector<vector<int>>g(n);
    for( int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        g[u-1].push_back(v-1);
    }
    int ma=0;
    for( int i=0;i<n;i++){
            int x=dfs(i, g, dp);
           ma=max(ma, x);
    }
    cout<<ma<<endl;
	return 0;
}