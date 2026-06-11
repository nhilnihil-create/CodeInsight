#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i,n) for(int i = 0;i <n;i++)
int main(){
	int n, c,ans = 1<<30; cin >> n >> c;
	vector<vector<int>> D(c, vector<int>(c)),C(n,vector<int>(n)),t(3,vector<int>(c+1,0));
	rep(i, c) rep(j, c) cin >> D[i][j];
	rep(i, n) rep(j, n) cin >> C[i][j], t[(i + j) % 3][C[i][j] - 1]++;
	rep(i, c) rep(j, c) if (i != j) rep(k, c) {
		if (i != k && j != k) {
			int tt = 0;
			rep(l, c) tt += t[0][l] * D[l][i];
			rep(l, c) tt += D[l][j] * t[1][l];
			rep(l, c) tt += D[l][k] * t[2][l];
			if (tt < ans) ans = tt;
		}
	}cout << ans << endl;
}