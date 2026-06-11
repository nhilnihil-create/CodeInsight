/*------------------------------------
........Bismillahir Rahmanir Rahim....
..........created by Abdul Aziz.......
------------------------------------*/
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <set>
#include <list>
#include <stack>
#include <map>
#include <cstring>
#include <unordered_map>
#include <queue>
#define   mod  998244353
#define   int  long long 
#define   ld   long double
#define   pb   push_back
#define   vi  vector<int> 
#define   dbg(x)  cerr << #x << " = " << x << '\n'
#define   sz(x)  (int)x.size()
#define   all(a) (a.begin(),a.end())
#define   ff   first
#define   ss   second
#define   pii  pair<int,int> 
#define   lcm(a,b) (a*b)/__gcd(a,b) 
using namespace std;

int dp[13][100005];

inline void solve(){
    int yen; cin>>yen; 
    int a[13]={0,1,6,9,36,81,216,729,1296,6561,7776,46656,59049};
    fill(dp[0]+1,dp[0]+100005,1e9);
    for (int i=1;i<=12;i++){
    	for(int j=1;j<=yen;j++){
    		if (a[i]>j) dp[i][j] = dp[i-1][j] ; 
    		else dp[i][j] = min(dp[i-1][j],dp[i][j-a[i]]+1);
    	}
    }
    cout << dp[12][yen] << endl;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
