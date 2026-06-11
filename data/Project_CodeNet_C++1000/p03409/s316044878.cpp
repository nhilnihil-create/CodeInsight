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
#define FOR(i, a, b) for(ll i=(a); i < (ll)(b); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

bool rcomp(pair<int,int> l, pair<int,int> r){
	return l.second > r.second;
}

bool bcomp(pair<int,int> l, pair<int,int> r){
	return l.first < r.first;
}


int main(){
	int n;
	cin >> n;
	vector<pair<int,int>> red(n),blue(n);
	REP(i,n) cin >> red[i].first >> red[i].second;
	REP(i,n) cin >> blue[i].first >> blue[i].second;
	
	sort(red.begin(), red.end(), rcomp);
	sort(blue.begin(), blue.end(), bcomp);
	
	int ans = 0;
	vector<int> r(n,0);
	REP(i,n){
		REP(j,n){
			if(r[j]!=0) continue;
			if(red[j].first < blue[i].first && red[j].second < blue[i].second){
				ans++;
				r[j] = 1;
				break;
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}