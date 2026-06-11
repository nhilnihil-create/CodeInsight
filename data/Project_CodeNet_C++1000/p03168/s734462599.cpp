#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <complex>
#include <iomanip>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <cstring>
#include <set>

#define ll long long
#define ld long double
#define HS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define INF 0x3f3f3f3f3f3f3f3f
#define point complex <double> 
#define all(a) a.begin(), a.end()
#define pi acos(-1)
#define mod 1000000007


using namespace std;
int n;
ld coin[3000];
ld dp[3000][3000];
ld solve(int headCnt, int tailCnt)
{

	if (headCnt + tailCnt == n)
		return (headCnt > tailCnt);
	


	if (dp[headCnt][tailCnt] != -1.0)
		return dp[headCnt][tailCnt];

	ld ans = 0;
	ans += (solve(headCnt, tailCnt + 1) * (1.0 - coin[headCnt + tailCnt]));
	ans += solve(headCnt + 1, tailCnt) * coin[headCnt + tailCnt];

	return dp[headCnt][tailCnt] = ans;


}

int main() {
	HS;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> coin[i];

	for (int i = 0; i < 3000; i++)
		for (int j = 0; j < 3000; j++)
			dp[i][j] = -1.0;

	cout << setprecision(12) << solve(0, 0);

	return 0;
}