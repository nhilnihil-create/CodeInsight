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
    int n,ans=0; cin>>n; 
    int a[n],mn=1000;
    for (int i=0;i<n;i++){
        cin >> a[i];
        if (a[i]>0) mn = min(a[i],mn);
    }
    while (true){
        int c=1000,ok=1,fl=0;
        for (int i=0;i<n;i++){
            if (a[i]==0) ok=1;
            else  {
                if (ok) ans += mn;
                a[i] -= mn,ok=0; 
                if (a[i]>0) c=min(c,a[i]),fl=1;
            }
        }
        mn=c; 
        if (fl==0) break;
    }
    cout << ans << endl;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
