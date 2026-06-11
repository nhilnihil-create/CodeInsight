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
    int  r, c, odd = 0 ; 
    cin >> r >> c ; 
    vector <vector <int> > g(r+5,vector <int> (c+5)); 
    for (int i=1;i<=r;i++) { 
    	for (int j=1;j<=c;j++) { 
    		cin >> g[i][j] ; 
    		g[i][j] = ( (g[i][j] & 1)? 1 : 0 ) ; 
    	} 
    } 
    vector <pair<pii,pii>> res; 
    pair <pii,pii> p;
    for (int i=1;i<=r;i++){
    	for (int j=1;j<c;j++){
    		if (g[i][j]&1) {
    			g[i][j+1]++;
    			p.ff.ff=i; p.ff.ss=j;
    			p.ss.ff=i; p.ss.ss=j+1;
    			res.pb(p);
    		}
    	}
    }
    for (int i=1;i<r;i++){
    	if (g[i][c]&1){
    		g[i+1][c]++;
    		p.ff.ff=i; p.ff.ss=c;
    		p.ss.ff=i+1; p.ss.ss=c;
    		res.pb(p);
    	}
    }
    cout << sz(res) << endl;
    for (auto &it: res) {
    	printf("%lld %lld %lld %lld\n",it.ff.ff,it.ff.ss,it.ss.ff,it.ss.ss);
    }
} 

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
/*
2 3
1 2 3
0 1 1


3 2
1 0
2 1
1 0

1 5
9 9 9 9 9

*/