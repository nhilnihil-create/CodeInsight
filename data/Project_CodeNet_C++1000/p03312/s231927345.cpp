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
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<ll,ll> P;
typedef vector<P> vpl;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
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


int main(){
	ll n; cin >> n;
	vl a(n); rep(i,n) cin >> a[i];
	vl sum(n+1,0);
	rep(i,n) sum[i+1] += sum[i] + a[i];
	vpl v(4);
	ll ans = linf;
	REP(i,2,n-1){
		ll left = sum[i];
		ll right = sum[n] - sum[i];
		auto itrl = lower_bound(all(sum),(sum[i]+1)/2);
		v[0].first = *itrl; v[0].second = sum[i] - *itrl;
		if(itrl == sum.begin()) v[1] = make_pair(0,inf);
		else{
			itrl--;
			v[1].first = *itrl; v[1].second = sum[i] - *itrl;
		}
		auto itrr = lower_bound(all(sum),sum[i] + (right+1)/2);
		v[2].first = *itrr - sum[i]; v[2].second = sum[n] - *itrr;
		if(itrr == sum.begin()) v[3] = make_pair(0,inf);
		else{
			itrr--;
			v[3].first = *itrr - sum[i]; v[3].second = sum[n] - *itrr;
		}
		rep(j,2){
			REP(k,2,4){
				ll mx = max({v[j].first,v[j].second,v[k].first,v[k].second});
				ll mn = min({v[j].first,v[j].second,v[k].first,v[k].second});
				//print2(j,k);
				//print2(v[j].first,v[j].second);
				//print3(v[k].first,v[k].second,mx-mn);
				chmin(ans,mx-mn);
			}
		}
	}
	cout << ans << endl;
}