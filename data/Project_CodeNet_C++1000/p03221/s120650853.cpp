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
	map <int,int> pre;
	map <int,string> res;
    int n,m; cin>>n>>m; 
    vector <pii> v(m),h(m);
    for (int i=0;i<m;i++){
    	cin>>v[i].ss>>v[i].ff;
    	h[i]=v[i];
    }
    sort(v.begin(), v.end());
    for (int i=0;i<m;i++){
    	string s=to_string(v[i].ss);
    	pre[v[i].ss]++;
    	string ss=to_string(pre[v[i].ss]);
    	while (sz(s)<6) s.insert(s.begin(),'0');
    	while (sz(ss)<6) ss.insert(ss.begin(),'0');
    	res[v[i].ff]=s+ss;
    }
    for (int i=0;i<m;i++){
    	cout << res[h[i].ff] << endl;
    }
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
