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
	int n;
	cin >> n;
	vector<int> b(n), ans;
	rep(i,n) cin >> b[i];
	rep(i,n){
		for(int j = b.size()-1; j >= 0; --j){
			if(j+1 == b[j]){
				ans.push_back(b[j]);
				b.erase(b.begin() + j);
				break;
			}
		}
	}
	if(!b.empty()){
		cout << -1 << endl;
		return 0;
	}
	for(int i = n-1; i >= 0; --i) cout << ans[i] << endl;
	return 0;
}