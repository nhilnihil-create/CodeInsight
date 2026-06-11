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
	int a,b;
	cin >> a >> b;
	int ans=0;
	for(int i=a; i<=b; i++){
		string s = to_string(i);
		bool same = true;
		REP(j, s.size()/2){
			if(s[j] != s[s.size()-1-j]) same=false;
		}
		if(same) ans++;
	}
	cout << ans << endl;
	
	return 0;
}