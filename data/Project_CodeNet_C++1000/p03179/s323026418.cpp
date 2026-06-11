#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <utility>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

//const long double PIL = 3.141592653589793238462643383279502884L;
//const double PI = 3.14159265358979323846;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int,int>> vii;
#define sz(a) int((a).size())
#define all(c) (c).begin(), (c).end()

const int N = 3001;
const int MOD = 1e9 + 7;
char s[N];
int dp[N][N];

int main() {
	//~ ios::sync_with_stdio(0);
	//~ cin.tie(0);
	int n;
	scanf("%d%s", &n, s);

	for (int i = 1; i <= n; i++) dp[1][i] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (s[i-2] == '<')
				dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = (dp[i-1][i-1] - dp[i-1][j-1] + MOD) % MOD;
			dp[i][j] = (dp[i][j-1] + dp[i][j]) % MOD;
		}
	}
	/*
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) printf("%d ", dp[i][j]);
		puts("");
	}
	*/
	printf("%d\n", dp[n][n]);
}
