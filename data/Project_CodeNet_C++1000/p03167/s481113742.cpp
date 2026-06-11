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
vector<int>xx={1,0}; vector<int>yy={0,1};
long long int dfs(int x, int y, vector<vector<char>>& grid, vector<vector<long long int>>&dp){
    if( x==grid.size()-1 && y==grid[0].size()-1) return 1;
    if( dp[x][y]!=-1) return dp[x][y];
   long long int ans=0;

    for( int i=0;i<2;i++){
        int r=x+xx[i];
        int c=y+yy[i];
        if( r>=grid.size() || c>=grid[0].size()) continue;
        if( grid[r][c]=='.'){
            ans= (ans%1000000007+dfs(r,c,grid, dp)%1000000007)%1000000007;
        }
    }
	return dp[x][y]= ans%1000000007;
}
/********** Main()  function **********/
int main()
{std::ios::sync_with_stdio(false);
	int r,c;
    cin>>r>>c;
    vector<vector<char> >grid(r, vector<char>(c));
    vector<vector<long long int>>dp(r+1,vector<long long int> ( c+1, -1));
    for( int i=0;i<r;i++){
        for( int j=0;j<c;j++)
        cin>>grid[i][j];
    }
    // queue<int> qx;
    // queue<int> qy;
    // qx.push(0);
    // qy.push(0);
    // int ans=1;
    // while( !qx.empty()){
    //     int row=qx.front();
    //     int col=qy.front();
    //     qx.pop(); qy.pop();
    //     if( row==r-1 && col==c-1) { break;}
    //     if( row+1<r && col+1<c) ans=(ans*2)%1000000007;
    //     if( row+1<r && col+1<c && grid[row+1][col]=='#' && )

    // }
    cout<<dfs(0,0,grid, dp)<<endl;
	return 0;
}