#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int ans = 0;
	map<string, int> blue, red;
	rep(i,n){
		string s;
		cin >> s;
		++blue[s];
	}
	int m;
	cin >> m;
	rep(i,m){
		string t;
		cin >> t;
		++red[t];
	}
	for(auto p : blue){
		chmax(ans, p.second - red[p.first]);
	}
	cout << ans << endl;
	return 0;
}