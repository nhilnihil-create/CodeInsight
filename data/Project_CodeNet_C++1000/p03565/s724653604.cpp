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
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	if(n < m){
		cout << "UNRESTORABLE" << endl;
		return 0;
	}
	for(int i = n-m; i >= 0; --i){
		bool match = true;
		rep(j,m){
			if(s[i+j] == '?') continue;
			if(s[i+j] != t[j]) match = false;
		}
		if(match){
			rep(j,m) s[i+j] = t[j];
			break;
		}
		if(i == 0){
			cout << "UNRESTORABLE" << endl;
			return 0;
		}
	}
	rep(i,n){
		if(s[i] == '?') s[i] = 'a';
	}
	cout << s << endl;
	return 0;
}