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
	ll n,m;
	cin >> n >> m;
	vector<pair<ll,ll>> city(m);
	vector<vector<ll>> pref(n);
	REP(i,m){
		cin >> city[i].first >> city[i].second;
		pref[city[i].first-1].push_back(city[i].second);
	}
	map<ll,ll> order;
	REP(i,n){
		sort(pref[i].begin(),pref[i].end());
		REP(j,pref[i].size()){
			order.insert(make_pair(pref[i][j],j+1));
		}
	}
	REP(i,m){
		string number = to_string(city[i].first);
		int digit = 6-(int)number.size();
		cout << string(digit,'0') << number;
		number = to_string(order[city[i].second]);
		digit = 6-(int)number.size();
		cout << string(digit,'0') << number << endl;
	}
	
	return 0;
}