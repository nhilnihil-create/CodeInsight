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
	vector<vector<int>> a(2, vector<int>(n));
	rep(i,2)rep(j,n) cin >> a[i][j];
	int ans = 0;
	rep(k,n){
		int score = 0;
		for(int i = 0; i <= k; ++i) score += a[0][i];
		for(int j = k; j < n; ++j) score += a[1][j];
		chmax(ans, score);
	}
	cout << ans << endl;
	return 0;
}