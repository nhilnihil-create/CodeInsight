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
#include <iomanip>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int main(){
	int h,w,d,q;
	cin >> h >> w >> d;
	vector<pair<int,int>> a(h*w);
	REP(i,h) REP(j,w){
		int in;
		cin >> in;
		a[in-1].first = i;
		a[in-1].second = j;
	}
	
	vector<ll> cost(h*w);
	for(int i=0; i<h*w; i++){
		if(i<d){
			cost[i] = 0;
			continue;
		}
		cost[i] = cost[i-d];
		cost[i] += abs(a[i].first-a[i-d].first) + abs(a[i].second-a[i-d].second);
	}
	
	vector<ll> ans;
	cin >> q;
	REP(i,q){
		int l,r;
		cin >> l >> r;
		ans.push_back(cost[r-1]-cost[l-1]);
	}
	
	REP(i,q) cout << ans[i] << endl;
		
	return 0;
}