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
	ll n,m;
	cin >> n >> m;
	
	ll ans = 0;
	if(n==1 && m==1){
		ans += 1;
	}else if(n==1 || m==1){
		ans += max(n,m)-2;
	}else{
		ans += max((ll)0,n-2)*max((ll)0,m-2);
	}
	cout << ans << endl;
	
	return 0;
}