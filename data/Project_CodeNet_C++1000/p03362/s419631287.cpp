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

int a[55556];

int main(){
	int n;
	cin >> n;
	
	for(int i=2; i<=55555; i++){
		if(a[i]!=0) continue;
		for(ll j=(ll)i*i; j<=55555; j+=i){
			a[j] = 1;
		}
	}
	
	vector<int> ans;
	for(int i=2; i<=55555; i++){
		if(a[i]!=0) continue;
		
		if(i%5==1) ans.push_back(i);
		if((int)ans.size()==n) break;
		
	}
	
	REP(i,n){
		if(i!=0) cout << " ";
		cout << ans[i];
	}
	cout << endl;
	
	return 0;
}