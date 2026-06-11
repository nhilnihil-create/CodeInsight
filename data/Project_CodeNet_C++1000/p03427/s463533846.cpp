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
    string  s; 
    cin >> s ; 
    int  len=sz(s),ans=0; 
    if (len==1) ans=s[0]-'0';
    else {
        bool ok=false;
        for (int i=1;i<len;i++)
            if (s[i] < '9') ok=true;
        if (ok) {
            for (int i=0;i<len;i++){
                if (i==0) ans += s[i]-'1';
                else ans += 9;
            }
        }
        else {
            for (int i=0;i<len;i++) ans += s[i]-'0';
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
