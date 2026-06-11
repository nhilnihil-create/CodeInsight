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
    int n,g=0; cin>>n; 
    vi a(n+1),l(n+2),r(n+2);
    for (int i=0;i<n;i++) cin >> a[i] ; 
    for (int i=0;i<n-1;i++) 
        l[i+1] = __gcd(l[i],a[i]); 
    for (int i=n-1;i>=1;i--) 
        r[i-1] = __gcd(r[i],a[i]); 
    int ans = 0; 
    for (int i=0;i<n;i++) 
        ans = max(ans,__gcd(l[i],r[i])); 
    cout << ans << endl;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
