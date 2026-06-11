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

bool comp(pair<ll,ll> l, pair<ll,ll> r){
	return l.first+l.second > r.first+r.second;
}

int main(){
	int n;
	cin >> n;
	vector<pair<ll,ll>> dish(n);
	REP(i,n) cin >> dish[i].first >> dish[i].second;
	sort(dish.begin(), dish.end(), comp);
	
	ll taka=0,ao=0;
	REP(i,n){
		if(i%2==0){
			taka += dish[i].first;
		}else{
			ao += dish[i].second;
		}
	}
	
	cout << taka - ao << endl;
	
	
	return 0;
}