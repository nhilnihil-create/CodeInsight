#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("unroll-loops") 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#define int long long
#define fr(i,a,b) for(int i = a ; i <= b ; ++i)
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define pb push_back
#define fst first
#define snd second
using namespace __gnu_pbds;
using ordered_set =
 tree<int, null_type,less<int>,
 rb_tree_tag,tree_order_statistics_node_update>;
//find_by_order(k):returns iterator to kth element starting from 0
//order_of_key(k):returns count of elements strictly smaller than k
typedef long long ll;typedef pair<int, int> pii;
typedef vector<int> vi;typedef long double ld;
template<class T>
using min_heap = priority_queue<T,vector<T>,greater<T>>; 
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template<typename T> T lcm(T a, T b){return(a*(b/gcd(a,b)));}
template<typename T> 
void remdup(vector<T>& v) {
	sort(all(v)); v.erase(unique(all(v)), v.end());
}
template<typename T> void re(vector<T> &v) {trav(i,v) cin >> i;}
void unsyncIO() { ios_base::sync_with_stdio(0); cin.tie(0); }
#ifdef np
#include "C:\Users\navodit\Desktop\mycodes\pr.h"
#else
#define trace(...)
#endif

#define MOD 1000000007  





void solve(){
	int n , m; 
	cin >> n >> m; 
	vi a(n);
	re(a);
	vi b(m) , c(m);
	rep(i,0,m){
		cin >> b[i] >> c[i];
	}
	vi idx(m);
	iota(all(idx),0);
	auto cmp  =[&](int i ,int j){return c[i] > c[j];};
	sort(all(idx),cmp);
	multiset<int>se(all(a)) ; 
	int mx = n ;
	trav(i,idx){
		int cur = min(mx,b[i]);
		rep(j,0,cur) se.insert(c[i]);
		mx-=cur;
	}
	while(sz(se)>n) se.erase(se.begin());
	ll ans = 0 ;
	trav(i,se) ans+=i;
	cout << ans << endl; 
}

signed main() {
	unsyncIO();
	int tt =1 ;
	// cin >> tt;
	rep(i,0,tt) solve();













#ifdef np
	cout <<endl<<endl<< "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}
