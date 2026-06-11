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
    string  s,t; 
    cin >> s >> t; 
    map <char,int> oc1,oc2;
    for (int i=0;i<sz(s);i++) oc1[s[i]]++;
    for (int i=0;i<sz(t);i++) oc2[t[i]]++;
    vector <int> a,b;
    for (auto &it: oc1) a.pb(it.ss); 
    for (auto &it: oc2) b.pb(it.ss); 
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if (a != b) cout << "No" << endl;
    else cout << "Yes"<< endl;
    return;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
