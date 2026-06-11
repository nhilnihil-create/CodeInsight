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

    string s; int n,k;
    cin >> n >> k >> s ;
    vi p0(n+1,0),p1(n+1,0);
    n = 1;
    if (s[0] == '0') p1[1] = 0, n++;
    for (int i=1,c=1;i<sz(s);i++){
    	if (s[i] != s[i-1]) {
    		p1[n++] = c; 
    		c = 1; 
    	}
    	c += (s[i]==s[i-1]);
    	if (i==sz(s)-1) p1[n] = c;
    }
    for (int i=1;i<=n;i++) p1[i] += p1[i-1] ; 
    int ans=0;
	for (int i=min(k*2+1,n);i<=n;i++){
		if (i&1) 
			ans = max(ans,p1[i]-p1[max(0LL,i-(k*2+1))]);
		else 
			ans = max(ans,p1[i]-p1[max(0LL,i-(k*2))]);
	}
	if(ans == 0) ans = n ; 
	cout << ans << endl;
    /// 110011001100
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
