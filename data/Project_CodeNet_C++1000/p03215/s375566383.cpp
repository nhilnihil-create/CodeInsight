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
#include <functional>
#define   mod  998244353
#define   int  long long 
#define   ld   long double
#define   pb   push_back
#define   vi   vector<int> 
#define   co(x)  cout << x << '\n' 
#define   dbg(x)  cerr << #x << " = " << x << '\n' 
#define   bitcount(x)  (int)__builtin_popcount(x) 
#define   sz(x)  (int)x.size()
#define   all(a) a.begin(),a.end() 
#define   ff   first
#define   ss   second
#define   pii  pair<int,int> 
#define   lcm(a,b) (a*b)/__gcd(a,b) 
using namespace std;

inline void solve(){
    int  n, k ; 
    cin >> n >> k ; 
    vi  a(n), v ; 
    for (int &i: a) cin >> i ; 
    for (int i=0;i<n;i++){
        int sum = 0 ; 
        for (int j=i;j<n;j++){
            sum += a[j] ; 
            v.emplace_back(sum) ; 
        }
    }

    int ans = 0 ; 
    for (int i=40;i>=0;i--){ 
        int c = 0 ; 
        vi cur ; 
        for (auto &it: v){ 
            int x = it;
            if (x&(1LL<<i)) {
                c++ ; 
                cur.pb(x) ; 
            }
        }
        if (c>=k){ 
            ans += (1LL<<i) ; 
            v = cur ; 
        }
    }
    co(ans) ; 
}

signed main()
{
    ios_base::sync_with_stdio(false) ; 
    cin.tie(0),cout.tie(0) ; 
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
