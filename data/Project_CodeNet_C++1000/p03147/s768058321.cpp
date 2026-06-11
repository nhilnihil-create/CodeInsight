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
	ll n;
	cin >> n;
	vector<ll> h(n);
	REP(i,n) cin >> h[i];
	
	ll ans=0;
	ll mizu=0;
	REP(i,n){
		if(mizu < h[i]){
			ans += h[i]-mizu;
		}
		mizu = h[i];
	}
	
	cout << ans << endl;
	
	return 0;
}