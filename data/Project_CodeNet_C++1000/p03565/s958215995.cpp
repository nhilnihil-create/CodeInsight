#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, int> LP;
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
	bool ok = false;
	for(int i = n-1; i >= 0; --i){
		bool match = true;
		for(int j = 0; j < m; ++j){
			if(i+j >= n){
				match = false;
				break;
			}
			if(s[i+j] == '?') continue;
			if(s[i+j] != t[j]) match = false;
		}
		if(match){
			for(int j = 0; j < m; ++j){
				s[i+j] = t[j];
			}
			ok = true;
			break;
		}
	}
	if(!ok){
		cout << "UNRESTORABLE" << endl;
		return 0;
	}
	rep(i,n){
		if(s[i] == '?') s[i] = 'a';
	}
	cout << s << endl;
	return 0;
}