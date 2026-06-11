#define _USE_MATH_DEFINES
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <math.h>
#include <complex>
#include <cassert>
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define case(i) cout<<"Case #"<<i<<": "
using namespace std;
typedef long long int ll;
typedef complex<double> com;
const int mod = 1e9 + 7;
const int MOD = 998244353;
const ll INF = 4e18;



int main() {
	char s[10000]; scanf("%s",&s);
	int n = strlen(s);
	int x, y; scanf("%d %d",&x,&y);
	x += n; y += n;
	vector<int> a,xlen,ylen; int cnt = 0;
	rep(i, 0, n) {
		if (s[i] == 'F') cnt++;
		else {
			a.push_back(cnt);
			cnt = 0;
		}
	}
	a.push_back(cnt);
	rep(i, 0, a.size()) {
		if (i % 2) ylen.push_back(a[i]);
		else xlen.push_back(a[i]);
	}
	vector<vector<bool>> dp(a.size()+1);
	rep(i, 0, a.size()+1) dp[i].resize(2 * n+1,false);
	dp[0][n] = true;
	rep(i, 0, xlen.size())rep(j, 0, 2 * n+1) {
		if (dp[i][j]) {
			if(j+xlen[i]<=2*n)dp[i + 1][j + xlen[i]] = true;
			if(j-xlen[i]>=0&&i!=0)dp[i + 1][j - xlen[i]] = true;
		}
	}
	if (!dp[xlen.size()][x]) {
		printf("No");
		return 0;
	}
	rep(i, 0, a.size() + 1)rep(j, 0, 2 * n + 1) dp[i][j] = false;
	dp[0][n] = true;
	rep(i, 0, ylen.size())rep(j, 0, 2 * n + 1) {
		if (dp[i][j]) {
			if(j+ylen[i]<=2*n)dp[i + 1][j + ylen[i]] = true;
			if(j-ylen[i]>=0)dp[i + 1][j - ylen[i]] = true;
		}
	}
	if (!dp[ylen.size()][y]) {
		printf("No");
		return 0;
	}
	printf("Yes");
	return 0;
}