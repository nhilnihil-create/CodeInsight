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
	int n,a,b,c;
	cin >> n >> a >> b >> c;
	vector<int> l(n);
	REP(i,n) cin >> l[i];
	
	int ans = 100000000;
	for(int t=0; t < (int)pow(4,n); t++){
		int ta=0,tb=0,tc=0,cost=0;
		REP(i,n){
			int type = (t/(int)pow(4,i))%4;
			if(type == 0){
				if(ta!=0) cost+=10;
				ta += l[i];
			}else if(type==1){
				if(tb!=0) cost+=10;
				tb += l[i];
			}else if(type==2){
				if(tc!=0) cost+=10;
				tc += l[i];
			}
		}
		if(ta*tb*tc==0) continue;
		
		cost += abs(a-ta)+abs(b-tb)+abs(c-tc);
		
		chmin(ans, cost);
	}
	
	cout << ans << endl;
	
	return 0;
}