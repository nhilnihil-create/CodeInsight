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
	int n,m;
	cin >> n >> m;
	vector<int> k(m);
	vector<vector<int>> s(m);
	REP(i,m){
		cin >> k[i];
		REP(j,k[i]){
			int in;
			cin >> in;
			s[i].push_back(in-1);
		}
	}
	vector<int> p(m);
	REP(i,m) cin >> p[i];
	
	int ans=0;
	for(int bit=0; bit<(1<<n); bit++){
		bool light = true;
		REP(i,m){
			int sum=0;
			REP(j,k[i]){
				if(bit & (1<<s[i][j])) sum++;
			}
			if(sum%2!=p[i]) light=false;
		}
		if(light) ans++;
	}
	
	cout << ans << endl;
	
	return 0;
}