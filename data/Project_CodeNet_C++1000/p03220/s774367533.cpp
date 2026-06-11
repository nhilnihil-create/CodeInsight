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
    int n,ans=0; cin>>n; 
    ld T,A; cin >> T >> A ; 
    ld  a[n], dif=10000 ; 
    for (int i=0;i<n;i++) { 
        cin >> a[i] ; 
        ld  h = T-(a[i]*0.006); 
        if (abs(A-h)<dif){
          dif = abs(A-h); 
          ans = i+1;
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
