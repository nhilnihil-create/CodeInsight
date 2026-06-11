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
	vector<P> ans;
	if(n%2 == 0){
		for(int i = 1; i <= n; ++i){
			for(int j = i+1; j <= n; ++j){
				if(i+j == n+1) continue;
				ans.emplace_back(i, j);
			}
		}
	}
	else{
		for(int i = 1; i <= n; ++i){
			for(int j = i+1; j <= n; ++j){
				if(i+j == n) continue;
				ans.emplace_back(i, j);
			}
		}
	}
	cout << ans.size() << endl;
	for(auto p : ans){
		cout << p.first << " " << p.second << endl;
	}
	return 0;
}