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
	int n,k;
	cin >> n >> k;
	vector<int> v(n);
	REP(i,n) cin >> v[i];
	
	ll ans = 0;
	for(int border=0; border<=n; border++){
		for(int l=0; l<=border; l++){
			for(int r=n; r>=border; r--){
				ll value = 0;
				int count = 0;
				priority_queue<int> minus;
				
				for(int i=0; i<l; i++){
					value += v[i];
					count++;
					if(v[i] < 0) minus.push(-1*v[i]);
				}
				for(int i=n-1; i>=r; i--){
					value += v[i];
					count++;
					if(v[i] < 0) minus.push(-1*v[i]);
				}
				
				if(count > k) continue;
				while(k-count>0 && !minus.empty()){
					value += minus.top();
					minus.pop();
					count++;
				}
				chmax(ans, value);
			}
		}
	}
	
	cout << ans << endl;
	
	
	return 0;
}