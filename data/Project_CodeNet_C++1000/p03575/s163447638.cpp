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

int ver,edge,ans=0; 
vi g[55]; 
int deg[55]; 

signed main()
{
    cin >> ver >> edge ; 
    for (int i=1;i<=edge;i++){
        int u,v; cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    } 
    for (int i=1;i<=ver;i++)
        deg[i] = sz(g[i]);
    while (true){
        bool ok=true;
        for (int i=1;i<=ver;i++){
            if (deg[i]==1){
                deg[i]=0; 
                ok=false; 
                for (auto &it: g[i]){
                    if (deg[it]>0) {
                        deg[it]--; 
                        break;
                    }
                }
                ans++;
            }
        }
        if (ok) break;
    }
    cout << min(edge,ans) << endl;
    return 0;
}
