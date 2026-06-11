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
	string s;
	cin >> s;
	int n=s.size();
	
	vector<int> xc;
	vector<char> a;
	int count =0;
	REP(i,n){
		if(s[i]=='x'){
			count++;
			continue;
		}
		xc.push_back(count);
		count=0;
		a.push_back(s[i]);
	}
	xc.push_back(count);
	
	REP(i,(int)a.size()/2){
		if(a[i]!=a[(int)a.size()-1-i]){
			cout << "-1\n";
			return 0;
		}
	}
	int ans=0;
	REP(i,(int)xc.size()/2){
		ans += abs(xc[i]-xc[(int)xc.size()-1-i]);
	}
	
	cout << ans << endl;
	
	return 0;
}