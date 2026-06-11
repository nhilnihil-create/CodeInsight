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
    int  A, B, Q, x ; 
    cin >> A >> B >> Q ; 
    vi s(A),t(B);
    for (int &i: s) cin >> i ; 
    for (int &i: t) cin >> i ; 
    while (Q--){
        cin >> x ; 
        int  s2, t2 ; 
        auto  s1 = lower_bound(s.begin(),s.end(),x) ; 
        if (s1 == s.end()) s1-- ; 
        if (s1 == s.begin()) {
            if (A>1) s2 = *(s1+1) ; 
            else s2 = *s1;
        }
        else {
            if (A>1) s2 = *(s1-1) ; 
            else s2 = *s1;
        }
        auto  t1 = lower_bound(t.begin(),t.end(),x); 
        if (t1 == t.end()) t1-- ; 
        if (t1 == t.begin()) {
            if (B>1) t2 = *(t1+1) ; 
            else t2 = *t1;
        }
        else {
            if (B>1) t2 = *(t1-1) ; 
            else t2 = *t1;
        }
        int  ss[2]={*s1, s2} ,tt[2]={*t1, t2}; 
        int  ans = 2e12 ; 
        for (int i=0;i<2;i++){
            for (int j=0;j<2;j++){
                ans = min(ans, min(abs(x-ss[i]) + abs(ss[i]-tt[j]),abs(x-tt[i]) + abs(tt[i]-ss[j]))) ; 
            }
        }
        co( ans ) ; 
    }
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
