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
    int  r, g, b, n, ans = 0 ; 
    cin >> r >> g >> b >> n ; 
    for (int i=0;i<=n/r;i++){
        int s=i*r;
        for (int j=0;j<=(n-s)/g;j++){
            int rem = n - (s+j*g);
            if (rem%b==0 ) ans++;
           // cout << i << " " << j << " " << rem/b << endl;
        }
    }
    cout << ans << endl; 
} 

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
