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
	int n;
	string s;
	cin >> n >> s;
	
	vector<int> B(n+1),W(n+1);
	// B[i]  [0,i)
	B[0] = 0;
	for(int i=0; i<n; i++){
		if(s[i]=='#'){
			B[i+1] = B[i] + 1;
		}else{
			B[i+1] = B[i];
		}
	}
	// W[i] [i, n-1]
	W[n] = 0;
	for(int i=n-1; i>=0; i--){
		if(s[i]=='.'){
			W[i] = W[i+1] + 1;
		}else{
			W[i] = W[i+1];
		}
	}
	
	int ans=n;
	REP(i,n+1){
		chmin(ans, B[i]+W[i]);
	}
	
	cout << ans << endl;
	
	return 0;
}