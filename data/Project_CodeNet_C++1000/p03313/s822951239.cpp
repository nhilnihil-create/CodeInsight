#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>
#include <bitset>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef pair<ll,ll> P;
typedef vector<P> vpl;
typedef tuple<ll,ll,ll> tapu;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(int i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int inf = 1<<30;
const ll linf = 1LL<<62;
const int MAX = 510000;
ll dy[8] = {0,1,0,-1,1,-1,1,-1};
ll dx[8] = {1,0,-1,0,1,-1,-1,1};
const double pi = acos(-1);
const double eps = 1e-7;
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){
	if(a>b){
		a = b; return true;
	}
	else return false;
}
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){
	if(a<b){
		a = b; return true;
	}
	else return false;
}
template<typename T1,typename T2> inline void print2(T1 a, T2 b){cout << a << " " << b << "\n";}
template<typename T1,typename T2,typename T3> inline void print3(T1 a, T2 b, T3 c){
	cout << a << " " << b << " " << c << "\n";
}
const int mod = 1e9 + 7;
//const int mod = 998244353;

int main(){
	ll n; cin >> n;
	ll N = 1<<n;
	vl a(N); rep(i,N) cin >> a[i];
	vl ans(N,0);
	vl mx(N,0);
	vl sec(N,0);
	vl get(N,0);
	rep(i,N){
		if(mx[i] <= a[i]){
			sec[i] = mx[i];
			mx[i] = a[i];
			get[i] = i;
		}else if(sec[i] < a[i]){
			sec[i] = a[i];
		}
		if(i>0){
			ans[i] = max(ans[i-1], mx[i] + sec[i]);
		}
		rep(j,n){
			ll t = i | 1<<j;
			if(mx[t] < mx[i]){
				sec[t] = mx[t];
				mx[t] = mx[i];
				get[t] = get[i];
			}else if(mx[t] == mx[i]){
				if(get[t] != get[i]){
					sec[t] = mx[t];
					mx[t] = mx[i];
					get[t] = get[i];
				}
			}else{
				chmax(sec[t],mx[i]);
			}
			chmax(sec[t],sec[i]);
		}
	}
	REP(i,1,N) cout << ans[i] << "\n";
	//REP(i,0,N) print2(mx[i],sec[i]);
}