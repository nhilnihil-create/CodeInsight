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
    int n,m,ans=0; cin>>n>>m;
    vector <int> sw[m],p(m);
    for (int i=0;i<m;i++){
        int k; cin>>k;
        sw[i].resize(k); 
        for (int l=0;l<k;l++) cin>>sw[i][l],sw[i][l]--;
    }
    for (int &i: p) cin>>i; 
    for (int i=0;i<(1<<n);i++){
        bool ok=true;
        for (int j=0;j<m;j++){
            int c=0;
            for (int &k: sw[j]){
                if ((i>>k)&1) c++;
            }
            if (c%2 != p[j]) ok=false;
        }
        if (ok) ans++;
    }
    cout << ans << endl;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
