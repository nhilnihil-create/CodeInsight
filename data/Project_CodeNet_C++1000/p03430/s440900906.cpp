#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <numeric>
#include <bitset>
#include <ctime>
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;

const int maxN = 3e2 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

int dp[maxN][maxN][maxN];

int main(){
	time_t START = clock();
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(dp, 0, sizeof dp);
	string s; cin >> s;
	int n = s.size();
	int X; cin >> X;
	for (int len = 0; len < n; len++)
		for (int l = 0; l + len < n; l++){
			for (int i = 0; i <= X; i++){
				int r = l + len;
				if (l == r){
					dp[i][l][r] = 1;
					continue;
				}
				if (l + 1 < n)
					dp[i][l][r] = max(dp[i][l][r], dp[i][l + 1][r]);
				if (r > 0)
					dp[i][l][r] = max(dp[i][l][r], dp[i][l][r - 1]);
				if (s[l] == s[r])
					dp[i][l][r] = max(dp[i][l][r], dp[i][l + 1][r - 1] + 2);
				if (i > 0)
					dp[i][l][r] = max(dp[i][l][r], dp[i - 1][l + 1][r - 1] + 2);
			}
		}
	printf("%d\n", dp[X][0][n - 1]);
	time_t FINISH = clock();
	cerr << "Execution time: " << (ld)(FINISH - START) / CLOCKS_PER_SEC * 1000.0 << " milliseconds.\n";
	return 0;
}
 

