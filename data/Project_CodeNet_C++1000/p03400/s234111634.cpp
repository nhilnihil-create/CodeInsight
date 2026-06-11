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
    int n,day,rem,ans;
    cin >> n >> day >> rem ; 
    ans = n;
    while (n--){
        int a; cin>>a;
        int h=day/a;
        if (a*h+1>day) h--;
        ans += h;
    }
    cout << ans+rem << endl;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
