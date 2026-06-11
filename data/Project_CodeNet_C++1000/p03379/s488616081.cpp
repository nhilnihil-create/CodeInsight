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
    int a[n+1],b[n+1],f,s; 
    for (int i=1;i<=n;i++) {
        cin>>a[i]; 
        b[i]=a[i];
    }
    sort(a+1,a+n+1); 
    if (n&1) f=a[n/2],s=a[n/2+1]; 
    else f=a[n/2],s=a[n/2+1]; 
    for (int i=1;i<=n;i++){
        if (b[i]<=f) cout << s << endl;
        else cout << f << endl;
    }
} 

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
