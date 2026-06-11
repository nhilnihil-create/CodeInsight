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
	string t = "keyence";
	if(s == t){
		cout << "YES" << endl;
		return 0;
	}
	int n = s.size();
	for(int i = 0; i < n; ++i){
		for(int j = i; j < n; ++j){
			string u = "";
			for(int k = 0; k < n; ++k){
				if(i <= k && k <= j) continue;
				else u.push_back(s[k]);
			}
			if(u == t){
				cout << "YES" << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}