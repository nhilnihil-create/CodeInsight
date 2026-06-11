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
    n--; 
    vi c(n),s(n),f(n);
    for (int i=0;i<n;i++) cin>>c[i]>>s[i]>>f[i];
    for (int i=0;i<n;i++){
        int sum=c[i]+s[i];
        for (int j=i+1;j<n;j++){
            if (s[j]>=sum) sum=s[j];
            if (sum%f[j]) sum += (f[j]-(sum%f[j]));
            sum += c[j]; 
        }
        cout << sum << endl;
    }
    cout << 0 << endl;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
