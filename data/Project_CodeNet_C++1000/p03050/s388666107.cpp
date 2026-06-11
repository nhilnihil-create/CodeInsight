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
	ll n;
	cin >> n;
	
	ll ans = 0;
	if(n>2) ans = n-1;
	for(ll i=2; i*i<n; i++){
		if(n%i==0){
			if(n/i-1==i) continue;
			
			if(n/i>2){
				ans += n/i-1;
			}
		}
	}
	
	
	
	cout << ans << endl;
	
	
	return 0;
}