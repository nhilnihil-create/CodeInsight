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

int  n, m, ans = 0 ; 
int  p[100005] ; 
vi  g[100005],h ; 
map <int,bool> curvis,vis;

void dfs(int u){
    if (vis[u]) return;
    vis[u] = true ; 
    curvis[u] = true ; 
    h.pb(p[u]);
    for (auto &it: g[u])
      if (!vis[it]) dfs(it);
}

signed main()
{
    cin >> n >> m ; 
    for(int i=1;i<=n;i++) cin >> p[i] ; 
    for(int i=1;i<=m;i++) { 
      int  a, b ; 
      cin >> a >> b; 
      g[a]. pb(b) ; 
      g[b]. pb(a) ; 
    } 
    for (int i=1;i<=n;i++){ 
        h.clear(); 
        curvis.clear(); 
        dfs(i); 
        for (auto &it: h){ 
            if (curvis[it]) ans++; 
        } 
    } 
    cout << ans << endl ; 
    return 0;
}
