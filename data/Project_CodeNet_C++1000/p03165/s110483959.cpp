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
// vector<string> ans;
// void solve(string &a, string &b, int i, int j, string s){
//     if( i==a.size() && j==b.size()){ ans.push_back(s); return;}
//     if( i>=a.size() || j>=b.size()) return;
//     if( a[i]==b[j]){
//             s.push_back(a[i]);
//             solve( a, b, i+1, j+1, s);
//             s.pop_back();
//     }
//     else{
//         solve( a, b, i+1, j, s);
//         solve( a,b,i, j+1,s);
//     }
// }
/********** Main()  function **********/
int main()
{std::ios::sync_with_stdio(false);
	string a;
    string b;
    cin>>a>>b;
    vector<vector<int>>dp(a.size()+1, vector<int>(b.size()+1, -1));
    for( int i=0; i<dp.size(); i++){
        dp[i][0]=0;
        // dp[i][0]=0;
    }
    for( int i=0;i<dp[0].size();i++){
        dp[0][i]=0;
    }
    for( int i=1;i<dp.size();i++){
        for( int j=1;j<dp[0].size();j++){
            if( a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else{ dp[i][j]= max( dp[i-1][j], dp[i][j-1]); }
        }
    }
    string ans;
    int i=dp.size()-1, j=dp[0].size()-1;
    while( i>0 && j>0){
            if( b[j-1]==a[i-1]){ ans.push_back(a[i-1]); i--; j--;}
            else{
                int x=dp[i-1][j]; int y=dp[i][j-1];
                if( x>y) {i--;}
                else{
                    j--;
                }
            }

        }
    reverse(ans.begin(), ans.end());
    cout<<ans<<endl;
    // solve( a, b, 0,0,"");
    // sort(ans.begin(), ans.end());
    // cout<<"ans-"<< ans[ans.size()-1]<<" | ";
    // for( int i=0;i<ans.size();i++){
    //     cout<<ans[i]<<" ";
    // }
	// return 0;
}