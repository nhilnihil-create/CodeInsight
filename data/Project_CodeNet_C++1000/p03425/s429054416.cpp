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
	int n;
	cin >> n;
	vector<string> s(n);
	REP(i,n) cin >> s[i];
	
	map<char,ll> m;
	REP(i,n) m[s[i][0]]++;
	
	ll ans = 0;
	char a[5] = {'M','A','R','C','H'};
	for(int i=0; i<5; i++){
		for(int j=i+1; j<5; j++){
			for(int k=j+1; k<5; k++){
				ans += m[a[i]]*m[a[j]]*m[a[k]];
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}