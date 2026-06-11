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

inline void solve(){ 
    int n; cin>>n; 
    vi a(n),b(n);
    priority_queue<pii> pq; 
    for (int i=0;i<n;i++) { 
        cin >> a[i] >> b[i] ; 
        pq.push({a[i]+b[i],i}); 
    } 
    int  ans = 0 ; 
    for (int i=1;i<=n;i++){ 
        pii h=pq.top();
        pq.pop();
        if (i&1) ans += a[h.ss];
        else ans -= b[h.ss];
    } 
    cout << ans << endl ; 
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
/*
 
10 
 
4 
1 1 
2 2 
3 4 
5 1 
 
 
*/
