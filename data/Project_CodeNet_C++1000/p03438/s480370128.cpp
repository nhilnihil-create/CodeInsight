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
	vector<pair<int,int>> a(n);
	REP(i,n) cin >> a[i].first;
	REP(i,n) cin >> a[i].second;
	
	ll d[2]={};
	for(auto x:a){
		if(x.first > x.second) d[0] += x.first - x.second;
		if(x.first < x.second) d[1] += (x.second - x.first)/2;
	}
	
	if(d[0]==0 && d[1]==0){
		cout << "Yes\n";
		return 0;
	}
	
	if(d[0] <= d[1]){
		cout << "Yes\n";
	}else{
		cout << "No\n";
	}
	 
	
	return 0;
}