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
using namespace std;

inline void solve(){
    int n,m; cin>>n>>m; 
    vi pref(n+4,0);
    int cnt=m,ans=0;
    while (m--){
      int a,b;
      cin>>a>>b;
      pref[a]++;pref[b+1]--;
    }
    for (int i=1;i<=n;i++){
      pref[i] += pref[i-1];
      if (pref[i]==cnt) ans++;
    }
    cout << ans << endl;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
