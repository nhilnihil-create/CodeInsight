#include <iostream>
#include<vector>
#include<iomanip>
#include <cstring>
#include<algorithm>
using namespace std;
typedef long double ld;
#define rep(i,n) for(int i = 0;i <n;i++)
ld dp[310][310][310]; int n,m;
ld rec(int c1, int c2, int c3) {
	if (dp[c1][c2][c3] != -1) return dp[c1][c2][c3];
	if (c1 == c2 && c2 == c3 && c3 == 0) return 0.0;
	ld res = 0.0;
	if (c1 > 0) res += rec(c1 - 1, c2, c3)*c1;
	if (c2 > 0)res += rec(c1 + 1, c2 - 1, c3)*c2;
	if (c3 > 0)res += rec(c1, c2 + 1, c3 - 1)*c3;
	res += (ld)n;
	res *= (ld)1.0 / (c1 + c2 + c3);
	return dp[c1][c2][c3]=res;
}
int main(){
	cin >> n; vector<int> a(3,0);
	rep(i, n) {
		cin >> m;a[m - 1]++;
	}rep(i, 310) rep(j, 310) rep(k, 310) dp[i][j][k] = -1;
	cout << fixed << setprecision(10) << rec(a[0], a[1], a[2]) << endl;
}