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
    string cmp="keyence";
    string s; cin >> s;
    int len=sz(s); 
    bool ok=true;
    for (int i=0;i<7;i++){
        if (s[i] != cmp[i]){
            for (int j=len-1,k=6;k>=i;k--,j--){
                if (s[j] != cmp[k]) { ok=false; break; }
            }
            break;
        }
    }
    if (ok) cout << "YES" << endl; 
    else cout << "NO" << endl; 
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
