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
#define   ff   first
#define   ss   second
#define   pii  pair<int,int>
#define   psi  pair<string,pii> 
using namespace std;

bool cmp(psi a,psi b){
    if (a.ff==b.ff) return a.ss.ff >= b.ss.ff;
    return a.ff <= b.ff;
}

inline void solve(){
    int n,score; cin>>n;
    vector<psi> v; 
    for (int i=1;i<=n;i++){
        string  s; 
        cin >> s >> score ; 
        v.emplace_back(s,make_pair(score,i));
    }
    sort(v.begin(), v.end(),cmp); 
    for (auto &it: v) cout << it.ss.ss << endl;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
