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
	vector<vector<int>> F(n,vector<int>(10));
	vector<vector<int>> P(n,vector<int>(11));
	REP(i,n) REP(j,10) cin >> F[i][j];
	REP(i,n) REP(j,11) cin >> P[i][j];
	
	ll ans = -1*(1LL<<60);
	for(int bit=1; bit<(1<<10); bit++){
		ll sum=0;
		vector<int> a(n,0);
		
		REP(i,n){
			REP(j,10){
				if((bit&(1<<j)) && (F[i][j])) a[i]++; 
			}
			sum += P[i][a[i]];
		}
		chmax(ans, sum);
	}
	
	cout << ans << endl;
	
	
	return 0;
}