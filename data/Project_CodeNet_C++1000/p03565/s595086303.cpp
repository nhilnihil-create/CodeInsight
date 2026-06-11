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
    string s,t; 
    cin>>s>>t;
    int n=sz(s),m=sz(t); 
    for (int i=n-m;i>=0;i--){
        for (int j=i,k=0;j<n;j++,k++){
            if (s[j] != '?') 
                if (s[j] != t[k]) break; 
            if (k==m-1){
                for (k=0;k<m;k++,i++) s[i]=t[k];
                for (int i=0;i<n;i++) if (s[i]=='?') s[i]='a';
                cout << s << endl;
                return;
            }
        }
    }
    cout << "UNRESTORABLE" << endl;
    return;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
