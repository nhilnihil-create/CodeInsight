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

inline void solve(){
    int grid[4][4];
    for (int i=1;i<=3;i++){
        for (int j=1;j<=3;j++) {
            cin >> grid[i][j] ; 
        }
    }
    bool ok=true;
    if (grid[1][2]+grid[2][1] != grid[1][1]+grid[2][2]) ok = false ; 
    if (grid[3][2]+grid[2][3] != grid[2][2]+grid[3][3]) ok = false ; 
    if (grid[3][1]+grid[1][3] != grid[1][1]+grid[3][3]) ok = false ; 
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
