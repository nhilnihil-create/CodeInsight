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
    string  s; cin >> s;
    int len=sz(s),res=1000000;
    for (int i=0;i<len-2;i++){
        int ans=0,h=0,c=1;
        for (int j=i,k=100;j<i+3;j++,k/=10){
            ans += (s[j]-'0')*k;
        } 
        res = min(res,abs(ans-753));
    }
    cout << res << endl;
    
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
