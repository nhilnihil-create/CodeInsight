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
	int N, C;
	cin >> N >> C;
	vector<vector<int>> D(C, vector<int>(C));
	rep(i,C)rep(j,C) cin >> D[i][j];
	vector<vector<int>> c(N, vector<int>(N));
	rep(i,N)rep(j,N){
		cin >> c[i][j];
		c[i][j]--;
	}
	vector<vector<int>> cost(3, vector<int>(C, 0));
	rep(k,3){
		rep(l,C){
			int tmp = 0;
			rep(i,N)rep(j,N){
				if((i+j)%3 != k) continue;
				tmp += D[c[i][j]][l];
			}
			cost[k][l] = tmp;
		}
	}
	int ans = 1e9;
	rep(i,C)rep(j,C)rep(k,C){
		if(i == j || j == k || k == i) continue;
		int cmp = cost[0][i] + cost[1][j] + cost[2][k];
		chmin(ans, cmp);
	}
	cout << ans << endl;
	return 0;
}