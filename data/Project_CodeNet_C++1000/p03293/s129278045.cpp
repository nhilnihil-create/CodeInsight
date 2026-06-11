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
	string s,t;
	cin >> s >> t;
	
	int n = (int)s.size();

	
	
	
	REP(i,n){
		bool flag = true;
		REP(j,n){
			if(s[j] != t[(i+j)%n]) flag = false;
		}
		if(flag){
			cout << "Yes\n";
			return 0;
		}
	}
	
	cout << "No\n";

	
	return 0;
}