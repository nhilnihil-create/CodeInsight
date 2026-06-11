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
	int n,m,x;
	cin >> n >> m >> x;
	vector<bool> a(n+1,false);
	REP(i,m){
		int in;
		cin >> in;
		a[in] = true; 
	}
	
	int ans,cost=0;
	for(int i=x+1; i<=n; ++i){
		if(a[i]) cost++;
	}
	ans = cost;
	cost=0;
	for(int i=x-1; i>=0; --i){
		if(a[i]) cost++;
	}
	chmin(ans,cost);
	
	cout << ans << endl;
	
	return 0;
}