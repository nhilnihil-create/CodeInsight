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
	int n,k,in;
	cin >> n >> k;
	vector<int> x;
	REP(i,n){
		cin >> in;
		x.push_back(in);
	}
	
	ll ans = 1LL<<60;
	for(int i=0; i<n-k+1; i++){
		int a=0;
		a = abs(x[i]) + abs(x[i+k-1]-x[i]);
		chmin(a, abs(x[i+k-1]) + abs(x[i+k-1]-x[i]));
		chmin(ans, (ll)a);
	}
	
	cout << ans << endl;
	
	return 0;
}