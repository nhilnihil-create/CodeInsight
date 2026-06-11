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
    int n,fsum=0,ssum=0,ans=0,sum=0; cin>>n; 
    vi a(n),b(n);
    for (int &i: a) cin>>i, fsum += i; 
    for (int &i: b) cin>>i, ssum += i; 
    if (fsum<ssum) cout << -1 << endl, exit(0);
    priority_queue<int> pq;
    for (int i=0;i<n;i++){
        if (a[i]<b[i]) ans++,sum += (b[i]-a[i]);
        else pq.push(a[i]-b[i]);
    }
    while (sum>0){
        sum -= pq.top();
        pq.pop();
        ans++;
    }
    cout << ans << endl;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
