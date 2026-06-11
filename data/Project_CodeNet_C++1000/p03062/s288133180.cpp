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
    int n,neg=0,sum=0,mn=1000000001; cin>>n; 
    vi a(n);
    for (int i=0;i<n;i++) {
    	cin >> a[i];
    	if (a[i]<0) neg++;
    	sum += abs(a[i]);
    	mn = min(mn,abs(a[i]));
    } 
    if (neg&1) sum -= 2*mn;
    printf("%lld\n",sum);
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
/*



*/