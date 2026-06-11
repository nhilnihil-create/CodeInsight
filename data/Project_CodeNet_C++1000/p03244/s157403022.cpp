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

bool comp(pair<ll,ll> L, pair<ll,ll> R){
	return L.second > R.second;
}

int main(){
	ll n;
	cin >> n;
	vector<ll> v(n);
	REP(i,n) cin >> v[i];
	
	map<ll,ll> codd,ceven;
	REP(i,n){
		if(i%2){
			codd[v[i]]++;
		}else{
			ceven[v[i]]++;
		}
	}
	
	vector<pair<ll,ll>> odd,even;
	for(auto x: codd) odd.push_back(x);
	for(auto x: ceven) even.push_back(x);
	sort(odd.begin(),odd.end(),comp);
	sort(even.begin(),even.end(),comp);
	
	ll ans;
	if(odd[0].first!=even[0].first){
		ans = n/2 - odd[0].second;
		ans += n/2 - even[0].second;
	}else if(1==odd.size() || 1==even.size()){
		ans = n/2;
	}else{
		ans = n - odd[0].second - even[1].second;
		chmin(ans, n - odd[1].second - even[0].second);
	}
	
	cout << ans << endl;
	
	return 0;
}