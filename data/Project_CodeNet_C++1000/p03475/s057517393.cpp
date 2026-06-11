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
	vector<int> c(n-1),s(n-1),f(n-1);
	REP(i,n-1) cin >> c[i] >> s[i] >> f[i];
	
	vector<int> ans(n-1);
	
	for(int i=n-2; i>=0; i--){
		ans[i] = s[i] + c[i];
		for(int j=i+1; j<n-1; j++){
			if(ans[i] >= s[j]){
				if(ans[i]%f[j]==0){
					ans[i] += c[j];
				}else{
					ans[i] += f[j]-ans[i]%f[j];
					ans[i] += c[j];
				}
			}else{
				ans[i] = ans[j];
				break;
			}
		}
	}
	
	REP(i,n-1) cout << ans[i] << endl;
	cout << 0 << endl;
	
	return 0;
}