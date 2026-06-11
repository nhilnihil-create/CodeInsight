#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXL 8005

char S[MAXL];
vector<int> v[2];
bool dp[MAXL][MAXL];

int main() {
	int L;
	int x[2];

	scanf("%s%d%d", S, x, x + 1);

	for(L = 0; S[L]; L++);
	int c = 0, lt = L;
	for(int i = L - 1; i >= 0; i--) if(S[i] == 'T') {
		v[c].push_back(lt - i - 1);
		c ^= 1;
		lt = i;
	}
	for(int i = 0; S[i] == 'F' && i < L; i++) x[0]--;
	if(c == 1) swap(x[0], x[1]);
	x[0] = abs(x[0]);
	x[1] = abs(x[1]);

	bool ans = true;
	for(int i = 0; i < 2; i++) {
		dp[0][0] = true;
		for(int j = 1; j <= L; j++) dp[0][j] = false;
		for(int j = 1; j <= v[i].size(); j++) for(int k = 0; k <= L; k++) {
			dp[j][k] = (k >= v[i][j - 1] && dp[j - 1][k - v[i][j - 1]]) || (k + v[i][j - 1] <= L && dp[j - 1][k + v[i][j - 1]]);
		}
		ans &= dp[v[i].size()][x[i]];
	}

	if(ans) printf("Yes");
	else printf("No");
	return 0;
}
