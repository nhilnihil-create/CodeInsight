#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int Z = 8003;
const int N = 2 * Z + 1;
bool dp[2][2][N];
int X, Y;
char s[N];
int n;
int t;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	dp[0][0][Z] = dp[1][0][Z] = 1;
	scanf("%s", s);
	n = strlen(s);
	scanf("%d%d", &X, &Y);
	int pos = 0;
	while(pos < n && s[pos] == 'F') {
		pos++;
		X--;
	}
	t = 0;
	while(pos < n) {
		pos++;
		t ^= 1;
		int L = 0;
		while(pos < n && s[pos] == 'F') {
			pos++;
			L++;
		}
		for (int i = 0; i < N; i++)
			dp[t][1][i] = 0;
		for (int i = 0; i < N; i++) {
			if (!dp[t][0][i]) continue;
			dp[t][1][i - L] = dp[t][1][i + L] = 1;
		}
		for (int i = 0; i < N; i++)
			dp[t][0][i] = dp[t][1][i];
	}
	if (dp[0][0][Z + X] && dp[1][0][Z + Y])
		printf("Yes\n");
	else
		printf("No\n");

	return 0;
}
