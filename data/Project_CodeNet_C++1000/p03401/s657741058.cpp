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
	vector<ll> a(n);
	REP(i,n) cin >> a[i];
	
	// ans[i] = sum + diff[i];
	ll sum=0;
	vector<ll> diff(n);
	REP(i,n){
		if(i==0){
			sum += abs(a[0]);
		}else if(i==n-1){
			sum += abs(a[i]-a[i-1]);
			sum += abs(a[n-1]);
		}else{
			sum += abs(a[i]-a[i-1]);
		}
		
		if(i==0){
			diff[i] = abs(a[1]);
			diff[i] -= abs(a[0]) + abs(a[1]-a[0]); 
		}else if(i==n-1){
			diff[i] = abs(a[n-2]);
			diff[i] -= abs(a[n-1]-a[n-2]) + abs(a[n-1]);
		}else{
			diff[i] = abs(a[i+1]-a[i-1]);
			diff[i] -=  abs(a[i]-a[i-1])+abs(a[i+1]-a[i]);
		}
	}
	
	REP(i,n){
		cout << sum + diff[i] << endl;
	}
	
	return 0;
}