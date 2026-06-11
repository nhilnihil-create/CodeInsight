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
	map <int,int> ev,od; 
    int n,emax=0,omax=0; cin>>n; 
    for (int i=1;i<=n;i++){ 
    	int a;cin>>a; 
    	if (i&1) {
    		od[a]++; 
    		omax=max(omax,od[a]);
    	}
    	else {
    		ev[a]++;  
    		emax=max(emax,ev[a]); 
    	}
    } 
    int a,b,c,d; 
    priority_queue<int> e,o; 
    e.push(0),o.push(0); 
    for (auto &it: ev) e.push(it.ss); 
    for (auto &it: od) o.push(it.ss); 
    for (auto &it: ev) {
    	if (emax==it.ss) {
    		emax=it.ff;break;
    	}
    }
    for (auto &it: od) {
    	if (omax==it.ss) {
    		omax=it.ff;break; 
    	}
    }
    a=e.top();e.pop(); 
    b=e.top();e.pop(); 
    c=o.top();o.pop(); 
    d=o.top();o.pop(); 
    int ans=0;
    if (omax==emax)
    	ans = min(n-a-d,n-b-c);
    else ans = n-a-c; 
    cout << ans << endl;
} 

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
