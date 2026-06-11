#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <ctype.h>
#include <climits>
#include <queue>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define FOR(i, a, b) for(ll i=(a); i < (ll)(b); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int main(){
	ll a,b,q;
	cin >> a >> b >> q;
	vector<ll> s(a),t(b),x(q);
	REP(i,a) cin >> s[i];
	REP(i,b) cin >> t[i];
	REP(i,q) cin >> x[i];
	
	REP(i,q){
		ll ok,ng,mid; // 二部探索用
		ll sl,sr,tl,tr;
		
		ok = -1;
		ng = a;
		while(ng-ok>1){
			mid = (ok+ng)/2;
			if(s[mid] < x[i]) ok = mid;
			else ng = mid;
		}
		if(ok!=-1) sl = x[i]-s[ok];
		else sl = 1e11;
		if(ok!=a-1) sr = s[ok+1]-x[i];
		else sr = 1e11;
		
		ok = -1;
		ng = b;
		while(ng-ok>1){
			mid = (ok+ng)/2;
			if(t[mid] < x[i]) ok = mid;
			else ng = mid;
		}
		if(ok!=-1) tl = x[i]-t[ok];
		else tl = 1e11;
		if(ok!=b-1) tr = t[ok+1]-x[i];
		else tr = 1e11;
		
		ll ans = max(sr, tr);
		chmin(ans, max(sl, tl));
		chmin(ans, min(sr,tl)*2+max(sr,tl));
		chmin(ans, min(sl,tr)*2+max(sl,tr));
		
		cout << ans << endl;
	}
	
	
	return 0;
}