#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int m, k;
    cin >> m >> k;
	int two = (1<<m);
    if(k >= two){
        cout << -1 << endl;
        return 0;
    }
    if(m == 0){
        cout << "0 0" << endl;
		return 0;
    }
    if(m == 1){
        if(k == 0) cout << "0 0 1 1" << endl;
        else cout << -1 << endl;
		return 0;
    }
    vector<int> ans;
	ans.push_back(k);
	rep(i,two){
		if(i == k) continue;
		ans.push_back(i);
	}
	ans.push_back(k);
	for(int i = two-1; i >= 0; --i){
		if(i == k) continue;
		ans.push_back(i);
	}
	rep(i,ans.size()){
		cout << ans[i];
		if(i < ans.size()-1) cout << " ";
	}
	cout << endl;
    return 0;
}
