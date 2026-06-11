/********   All Required Header Files ********/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <iomanip>
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
double solve(int n, vector<double>&v, int k,vector<vector<double>>&dp){
    if( k>=v.size()) return 0;
	if( n==0){double a=1; for( int i=k;i<v.size();i++) a=a*(1-v[i]); return a;};
    if( n>v.size()-k) return 0; 

    if( n==1 && k==v.size()-1) return v[k];
    if( dp[n][k]!=2.0) return dp[n][k];
        double a=0;
        // if( n<=v.size()-k-1)
        a=(1-v[k])*solve( n, v,k+1, dp);
        double p=v[k]*solve( n-1,v,k+1, dp);
        // if( a!=0) return (a+p)/2 ;
        // else
        return dp[n][k]= (a+p);
}
/********** Main()  function **********/
int main()
{std::ios::sync_with_stdio(false);
	int n; cin>>n;
    vector<double> v(n);
    for( int i=0; i<n;i++)
    cin>>v[i];
    double x=0;
    // cout<<"K";
    vector<vector<double>>dp(n+1,vector<double>(n+1, 2.0));
    for( int i=n;i>n/2;i--){
        // double x=solve(i, v)/i;
        x=(x+solve( i, v, 0,dp));
    }
    cout<<setprecision(10);
    cout<<x<<endl;
	return 0;
}