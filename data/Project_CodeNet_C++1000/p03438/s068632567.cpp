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
    int n; cin>>n; 
    vi a(n),b(n);
    for (int &i: a) cin >> i ; 
    for (int &i: b) cin >> i ; 
    int ok = 0,s=0;
    for (int i=0;i<n;i++){
        s += max(0LL,(a[i]-b[i]));
        ok += max(0LL,(b[i]-a[i])/2); 
    }
    if (ok >= s ) printf("Yes\n");
    else printf("No\n");
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
