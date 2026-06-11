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
    string s; cin>>s;
    int dot=0,h=0,ans=1000001;
    for (int i=0;i<n;i++) 
        dot += (s[i] == '.'); 
    for (int i=0;i<n;i++){
        if (s[i]=='.') dot--;
        ans = min(ans,dot+h);
        if (s[i]=='#') h++;
    }
    cout << ans << endl;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}

/*
10 
#....###.# 


*/
