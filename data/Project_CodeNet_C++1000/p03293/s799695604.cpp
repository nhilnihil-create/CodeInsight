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
    string s,t;cin>>s>>t;
    int n=sz(s),len=n;
    while (len--){
        char c=s[n-1];
        if (s==t){
            cout << "Yes" << endl;
            return;
        }
        s.erase(s.begin()+n-1);
        s.insert(s.begin(),c);
    } 
    cout << "No" << endl;
    return;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
