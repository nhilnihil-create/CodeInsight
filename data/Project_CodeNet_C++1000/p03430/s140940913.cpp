#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#define my_abs(x) ((x) < 0 ? -(x) : (x))
#define mp std::make_pair
#define pb push_back
#define X first
#define Y second
typedef long long ll; 
char str[305]; 
int dp[305][305][305], n; 
int calc(int l, int r, int k)
{
	if (k < 0)
		return -1e9; 
	if (l > r || l >= n || r < 0)
		return 0; 
	if (~dp[l][r][k])
		return dp[l][r][k]; 
	int res = std::max(calc(l + 1, r, k), calc(l, r - 1, k)); 
	if (str[l] == str[r])
		res = std::max(res, calc(l + 1, r - 1, k) + (l != r) + 1); 
	return dp[l][r][k] = std::max(res, calc(l + 1, r - 1, k - 1) + (l != r) + 1); 
}
int main()
{
	// freopen("AGC021-D.in", "r", stdin); 
	int k; 
	scanf("%s%d", str, &k); 
	n = strlen(str); 
	memset(dp, -1, sizeof(dp)); 
	printf("%d\n", calc(0, n - 1, k));
	return 0; 
}
