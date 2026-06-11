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

int  r, c, d ; 
map <int,pii> m;

signed main()
{
    cin >> r >> c >> d ; 
    vi res(r*c+5);
    for (int i=0;i<r;i++) {
    	for (int j=0,in;j<c;j++){
    		cin >> in ; 
    		pii a; a.ff=i,a.ss=j ; 
    		m[in] = a ; 
    	}
    }
    for (int i=d;i <= r*c;i++){ 
    	res[i] = res[i-d] + abs(m[i].ff-m[i-d].ff) + abs(m[i].ss-m[i-d].ss) ; 
    	//cout << res[i] << " ";
    } 
    //cout << endl;
    int q; cin >> q; 
	while (q--){
		int l,r; cin >> l >> r ; 
		cout << (res[r]-res[l]) << endl ; 
	}
    return 0;
}
