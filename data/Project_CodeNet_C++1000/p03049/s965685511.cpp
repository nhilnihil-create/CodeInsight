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
	int n;
	cin >> n;
	vector<string> s(n);
	REP(i,n) cin >> s[i];
	
	int aandb=0,a=0,b=0, ans=0;
	REP(i,n){
		REP(j,s[i].size()-1){
			if(s[i][j]=='A'&&s[i][j+1]=='B') ans++;
		}
		
		if(s[i].front()=='B' && s[i].back()=='A') aandb++;
		else if(s[i].front()=='B') b++;
		else if(s[i].back()=='A') a++;
		
		
	}
	

	
	if(a > 0 && b > 0){
		ans += aandb+1;
		a--;
		b--;
		ans += min(a,b);
	}else if(a > 0 || b > 0){
		ans += aandb;
	}else{
		ans += max(aandb-1,0);
	}
	
	
	cout << ans << endl;
	
	
	return 0;
}