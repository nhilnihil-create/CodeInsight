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
	int n,k;
	cin >> n >> k;
	
	ll ans = 0;
	
	for(int b=k+1; b<=n; b++){
		ans += ((n+1)/b)*(b-k);
		if(k==0) ans--;
		if(n%b < b-1) ans += max(0, n%b + 1 - k);
	}
	
	cout << ans << endl;
	
	return 0;
}