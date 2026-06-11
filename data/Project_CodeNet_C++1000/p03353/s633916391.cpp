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
	string s;
	int k;
	cin >> s >> k;
	
	set<string> sub;
	REP(i,s.size()){
		for(ll j=1; j<=k; j++){
			sub.insert(s.substr(i,j));
		}
	}
	
	int index=1;
	string ans;
	for(auto x:sub){
		if(index==k){
			ans = x;
			break;
		}
		index++;
	}
	
	cout << ans << endl;
	
	return 0;
}
