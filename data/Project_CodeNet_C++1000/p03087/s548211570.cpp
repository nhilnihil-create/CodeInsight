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
	int N, Q;
	cin >> N >> Q;
	string s;
	cin >> s;
	vector<pair<int,int>> LR(Q);
	REP(i,Q){
		cin >> LR[i].first >> LR[i].second;
		// 0-based
		LR[i].first--;
		LR[i].second--;
	}
	
	vector<int> count(N,0);
	REP(i, N-1){
		if(i!=0) count[i] = count[i-1];
		if(s[i]=='A' && s[i+1]=='C'){
			count[i]++;
		}
	}
	count[N-1] = count[N-2];
	
	REP(i,Q){
		cout << count[LR[i].second-1]-count[LR[i].first-1] << endl;
	}
	
	
	return 0;
}