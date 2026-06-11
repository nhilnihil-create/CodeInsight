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
template<typename T1,typename T2> inline void print2(T1 a, T2 b){cout << a << " " << b << endl;}
template<typename T1,typename T2,typename T3> inline void print3(T1 a, T2 b, T3 c){
	cout << a << " " << b << " " << c << endl;
}
const int mod = 1e9 + 7;
//const int mod = 998244353;

int main(){
	ll n,k,q; cin >> n >> k >> q;
	vl a(n); rep(i,n) cin >> a[i];
	vpl b(n+1,P(inf,inf));
	rep(i,n){
		b[i].first = a[i];
		b[i].second = i;
	}
	sort(all(b));
	ll now = b[0].first;
	ll id = 0;
	vl split;
	split.push_back(-1);
	split.push_back(n);
	ll ans = linf;
	while(id < n){
		vl as;
		rep(i,split.size()-1){
			vl vv;
			REP(j,split[i]+1,split[i+1]){
				vv.push_back(a[j]);
			}
			if(vv.size()<k) continue;
			sort(all(vv));
			rep(j,vv.size()-k+1) as.push_back(vv[j]);
		}
		if(as.size()>=q){
			sort(all(as));
			chmin(ans,as[q-1]-as[0]);
		}
		while(id < n && now == b[id].first){
			split.push_back(b[id].second);
			id++;
		}
		sort(all(split));
		now = b[id].first;
	}
	cout << ans << endl;
}
