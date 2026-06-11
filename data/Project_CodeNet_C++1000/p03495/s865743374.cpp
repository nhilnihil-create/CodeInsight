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

bool comp(pair<int,int> l,pair<int,int> r){
	return l.second<r.second;
}

int main(){
	int n,k;
	cin >> n >> k;
	map<int,int> a;
	REP(i,n){
		int in;
		cin >> in;
		a[in]++;
	}
	
	if(k>=(int)a.size()){
		cout << 0 << endl;
		return 0;
	}
	
	vector<pair<int,int>> v;
	for(auto x:a){
		v.push_back(x);
	}
	
	sort(v.begin(),v.end(),comp);
	
	int ans=0;
	REP(i, (int)a.size()-k){
		ans += v[i].second;
	}
	
	cout << ans << endl;
	
	return 0;
}