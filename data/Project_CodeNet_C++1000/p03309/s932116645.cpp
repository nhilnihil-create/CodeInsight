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
	ll n,in;
	cin >> n;
	vector<ll> a(n);
	REP(i,n){
		cin >> in;
		a[i] = in - (i+1);
	}
	
	sort(a.begin(),a.end());
	ll b1;
	if(n%2) b1 = a[n/2];
	else b1 = (a[n/2-1]+a[n/2])/2;
	
	ll ans1=0;
	REP(i,n){
		ans1 += abs(a[i]-b1);
	}
	
	cout << ans1 << endl;
	
	return 0;
}