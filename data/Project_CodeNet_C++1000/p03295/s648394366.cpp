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
#include <list>
#include <stack>
#include <map>
#include <cstring>
#include <unordered_map>
#include <queue>
#include <functional>
#define   mod  998244353
#define   int  long long 
#define   ld   long double
#define   pb   push_back
#define   vi   vector<int> 
#define   co(x)  cout << x << '\n' 
#define   dbg(x)  cerr << #x << " = " << x << '\n' 
#define   bitcount(x)  (int)__builtin_popcount(x) 
#define   sz(x)  (int)x.size()
#define   all(a) a.begin(),a.end() 
#define   ff   first
#define   ss   second
#define   pii  pair<int,int> 
#define   lcm(a,b) (a*b)/__gcd(a,b) 
using namespace std; 


inline void solve(){
    int  n, m, inf = 1000000 ; 
    cin >> n >> m ; 
    vi g[100005];
    for (int i=0;i<m;i++){
    	int a,b; cin >> a >> b ; 
    	g[a]. pb(b) ; 
    	g[b]. pb(a) ; 
    }
    int  r = inf , ans = 0 ; 
    for (int i=1;i<n;i++){
	    for (auto it: g[i]){ 
	    	if (it>i)  
	    		r = min(r,it); 
	    }
	    if (r - i == 1) { 
	    	ans++; 
	    	r = inf ; 
	    }
    }
    co (ans) ; 
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
