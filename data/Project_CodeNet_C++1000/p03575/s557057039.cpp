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

int ver,edge,ans=0; 
vi g[55]; 
int deg[55]; 
stack <int> s;

signed main()
{
    cin >> ver >> edge ; 
    for (int i=1;i<=edge;i++){
        int u,v; cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    } 
    for (int i=1;i<=ver;i++){
        deg[i] = sz(g[i]);
        if (deg[i]==1) s.push(i);
    }
    while (s.size()){
        int x=s.top();
        s.pop();
        if (deg[x]==1) ans++;
        deg[x] = 0; 
        for (auto &it: g[x]){
            if (deg[it]>0){
                deg[it]--;
                if (deg[it]==1){
                    s.push(it);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
