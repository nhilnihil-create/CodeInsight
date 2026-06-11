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
    map <string,int> hash;
    int n; cin>>n; 
    string  s;
    cin >> s;
    hash[s]++; n--;
    bool ok=true;
    char c=s[sz(s)-1];
    while (n--){
        cin>>s; hash[s]++; 
        if (s[0] != c) ok=false;
        if (hash[s]>1) ok=false;
        c = s[sz(s)-1];
    }
    cout << (ok?"Yes":"No") << endl;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
