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
    map <int,int> in;
    int n,m,ans=0; cin>>n>>m;
    int a[m],dis[m-1];
    for (int i=0;i<m;i++) cin>>a[i];
    sort(a,a+m); 
    for (int i=1;i<m;i++) 
        in[(a[i]-a[i-1])]++; 
    ans = a[m-1]-a[0]; 
    n--;
    for (auto it=in.rbegin();it != in.rend();it++){
        if (it->ss >= n) {
            ans -= it->ff*n;
            break;
        }
        else {
            ans -= it->ss*it->ff;
            n -= it->ss;
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
