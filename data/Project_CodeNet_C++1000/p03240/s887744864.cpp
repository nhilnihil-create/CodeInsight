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
    int n,in=0; cin>>n; 
    vi X(n),Y(n),h(n);
    for (int  i=0 ; i<n ; i++) {
    	cin >> X[i] >> Y[i] >> h[i] ; 
    	if (h[i] != 0) in = i;
    }
    for (int x=0;x<=100;x++){ 
    	for (int y=0;y<=100;y++){ 
    		int H=h[in]+abs(x-X[in])+abs(y-Y[in]);
    		bool flag=true;
    		for (int i=0;i<n;i++){
    			if (h[i] != max(0LL,H-abs(x-X[i])-abs(y-Y[i]))) flag = false;
    		}
    		if (flag){
    			cout << x << " " << y << " " << H << endl; 
    			return;
    		}
    	}
    }
    
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
