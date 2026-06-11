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

int dis[10][10]; 

inline void solve(){ 
    int  h, w ; 
    cin >> h >> w ; 
    for (int i=0;i<10;i++) {
        for (int j=0;j<10;j++){
            cin >> dis[i][j] ;  
        }
    }
    for (int k=0;k<10;k++) {
        dis[k][k]=0;
        for (int i=0;i<10;i++){
            for (int j=0;j<10;j++){    
                dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    int ans=0;
    for (int i=0;i<h;i++){
        for (int j=0;j<w;j++){
            int x; cin>>x;
            if (x > -1) ans += dis[x][1];
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
