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
#include <functional>
#define   mod  998244353
#define   int  long long 
#define   ld   long double
#define   pb   push_back
#define   vi   vector<int> 
#define   co(x)  cout << x << '\n' 
#define   dbg(x)  cerr << #x << " = " << x << '\n' 
#define   bitcount(x)  (int)__builtin_popcount(x) 
#define   sz(x)  (int)x.size()
#define   all(a) a.begin(),a.end() 
#define   ff   first
#define   ss   second
#define   pii  pair<int,int> 
#define   lcm(a,b) (a*b)/__gcd(a,b) 
using namespace std;

int  n, m, ans = 0 ; 
int  a[1001][3]; 

signed main()
{
    cin >> n >> m ; 
    for (int i=1;i<=n;i++) cin >> a[i][0] >> a[i][1] >> a[i][2] ; 
    for (int i=0;i<8;i++){
        int cur[n+1];
        for (int j=1;j<=n;j++){
            int sum = 0 ; 
            for (int bit=0;bit<3;bit++){
                if (i / (1<<bit) % 2 == 0)  sum += a[j][bit] ; 
                else  sum -= a[j][bit] ; 
            }
            cur[j] = sum ; 
        }
        sort(cur+1,cur+n+1,greater<int> ());
        int s = 0 ;
        for (int j=1;j<=m;j++){
            s += cur[j] ; 
        }
        ans = max(ans, s) ; 
    }
    co ( ans ) ; 
    return 0;
}
/* 
3 2 
1 -2 3 
3 -5 -1 
1 2 3 
 
*/ 
