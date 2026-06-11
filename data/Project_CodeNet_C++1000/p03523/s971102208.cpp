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
	string s;
	cin >> s;
	string t = "AKIHABARA";
	int idx = 0;
	for(int i = 0; i < s.size(); ){
		if(idx == 9){
			cout << "NO" << endl;
			return 0;
		}
		if(s[i] == t[idx]){
			++idx;
			++i;
		}
		else if(t[idx] == 'A') ++idx;
		else{
			cout << "NO" << endl;
			return 0;
		}
	}
	if(idx < 8) cout << "NO" << endl;
	else cout << "YES" << endl;
	return 0;
}