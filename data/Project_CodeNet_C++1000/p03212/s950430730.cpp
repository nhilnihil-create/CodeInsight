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


ll n;

ll func(ll num, ll add, bool seven, bool five, bool three){
	num = num*10 + add;
	
	if(num > n){
		return 0;
	}
	
	
	int ret;
	if(seven&&five&&three) ret = 1;
	else ret = 0;
	
	ret += func(num, 7, true, five, three);
	ret += func(num, 5, seven, true, three);
	ret += func(num, 3, seven, five, true);
	return ret;
}

int main(){	
	cin >> n;
	
	ll ans = func(0,0,false,false,false);
	cout << ans << endl;
	
	return 0;
}