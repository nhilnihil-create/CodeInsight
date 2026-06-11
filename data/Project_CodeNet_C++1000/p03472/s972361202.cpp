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
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int main(){
	ll n,h;
	cin >> n >> h;
	vector<ll> a(n),b(n);
	REP(i,n){
		cin >> a[i] >> b[i];
	}
	
	sort(a.begin(),a.end(),greater<ll>());
	sort(b.begin(),b.end(),greater<ll>());
	
	ll amax = a[0];
	ll ans = 0;
	REP(i,n){
		if(h<=0 || amax>b[i]) break;
		ans++;
		h -= b[i];
	}
	
	if(h>0){
		ans += (ll)ceil((double)h/amax);
	}
	
	cout << ans << endl;
	
	
	return 0;
}