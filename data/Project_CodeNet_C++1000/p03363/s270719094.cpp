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
#include <cassert>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define FOR(i, a, b) for(ll i=(a); i < (ll)(b); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	REP(i,n) cin >> a[i];
	
	vector<ll> s(n+1);
	s[0] = 0;
	REP(i,n) s[i+1] = s[i]+a[i];
	map<ll,ll> m;
	REP(i,n+1){
		m[s[i]]++;
	}
	ll ans=0;
	for(auto x:m){
		ll k = x.second;
		ans += k*(k-1)/2;
	}
	
	cout << ans << endl;
	
	return 0;
}