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

ll gcd(ll a, ll b){
	if(b==0) return a;
	
	return gcd(b, a%b);
}

int main(){
	ll n;
	cin >> n;
	vector<ll> a(n);
	REP(i,n) cin >> a[i];
	
	//sort(a.begin(), a.end());
	
	ll monster=a[0];
	for(int i=1; i<n; ++i){
		/*
		if(a[i]%monster>0){
			monster -= a[i]%monster;
		}*/
		monster = gcd(monster,a[i]);
	}
	cout << monster << endl;
	
	return 0;
}