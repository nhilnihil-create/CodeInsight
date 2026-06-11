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
#define FOR(i, a, b) for(ll i=(a); i < (ll)(b); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int main(){
	int a,b;
	string s;
	cin >> a >> b >> s;
	
	bool ans = true;
	REP(i,s.size()){
		if(i == a){
			if(s[i]!='-') ans = false;
		}else{
			if('0' <= s[i] && s[i] <= '9'){
				
			}else{
				ans = false;
			}
		}
	}
	
	if(ans){
		cout << "Yes\n";
	}else{
		cout << "No\n";
	}
	
	return 0;
}