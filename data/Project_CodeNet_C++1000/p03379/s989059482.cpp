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
	vector<ll> x(n),xsort(n);
	REP(i,n) cin >> x[i];
	
	xsort = x;
	
	sort(xsort.begin(), xsort.end());
	
	ll median1 = xsort[n/2-1];
	ll median2 = xsort[n/2];
	
	REP(i,n){
		if(x[i]==median1  || x[i] < median1){
			cout << median2 <<endl;
		}else if(x[i]==median2|| x[i] > median2){
			cout << median1 <<endl;
		}
	}
	
	return 0;
}