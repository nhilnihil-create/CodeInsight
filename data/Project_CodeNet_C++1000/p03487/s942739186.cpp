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
	int n;
	cin >> n;
	vector<int> a(n);
	REP(i,n) cin >> a[i];
	
	map<int,int> m;
	REP(i,n){
		m[a[i]]++;
	}
	
	ll ans=0;
	for(auto x: m){
		int key = x.first;
		int value = x.second;
		if(key > value){
			ans += (ll)value;
		}else if(key < value){
			ans += (ll)(value-key);
		}
	}
	
	cout << ans << endl;
	
	return 0;
}