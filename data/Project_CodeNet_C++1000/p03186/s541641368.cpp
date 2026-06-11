#pragma GCC optimize("O3")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define F first
#define S second               
#define mp make_pair
#define ll long long

#define pb push_back
#define pbb pop_back
#define pf push_front
#define pff pop_front

#define sz(x) x.size()       
#define in(x) insert(x)                          
#define ioi exit(0);
#define bit(x) __builtin_popcount(x)

#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define upper(x,y,z) upper_bound(x + 1, x + 1 + y, z) - x
#define lower(x,y,z) lower_bound(x + 1, x + 1 + y, z) - x

using namespace std;
using namespace __gnu_pbds;
          
const int N = (int)1e5 + 5;
const int M = (int)1e6 + 6;
const ll INF = (ll)2e18 + 1;
const int mod = (int)1e9 + 7;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

long long a,b,c;

inline void solve(){
	cin >> a >> b >> c;
	if(c == 0){
		cout << a;
		return;
	}
	long long ans = 0;
	if(a == 0){
		if(b + 1 >= c){
			cout << b + c;		
		}  
		else cout << b + 1 + b;
		return;
	}
	if(b == 0){
		if(a + 1 >= c){
			cout << c; 
		}
		else cout << a + 1;
		return;
	}
	long long x = min(c,a + 1);
	ans += x;
	c -= x;
	x = min(b,c);
	ans += x * 2;
	b -= x;
	ans += b;
	cout << ans;
}

int main(){
   	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
   	int tt = 1;
   	//cin >> tt;
   	while(tt--){
   		solve();
   	}
   	return 0;
}                                