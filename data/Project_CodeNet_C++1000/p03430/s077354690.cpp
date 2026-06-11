#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;


typedef long long i64;
const int inf = (int)1.05e9;

int solve(char* s, int l, int r, int k, int n, vector<int>& memo)
{
	if(r - l <= 0) return 0;
	if(r - l == 1) return 1;

	int n1 = n + 1;
	int idx = k * n1 * n1 + l * n1 + r;
	int& val = memo[idx];

	if(val != -1)
		return val;
	val = 0;

	if(s[l] == s[r - 1]) {

		val = solve(s, l + 1, r - 1, k, n, memo) + 2;

	} else {

		if(k > 0) {
			val = solve(s, l + 1, r - 1, k - 1, n, memo) + 2;
		}

		int t1 = solve(s, l, r - 1, k, n, memo);
		int t2 = solve(s, l + 1, r, k, n, memo);
		val = max(val, max(t1, t2));
	}

	return val;
}

int main()
{
	char s[512];
	int k;

	scanf("%s%d", s, &k);

	int n = strlen(s);
	vector<int> memo;
	memo.resize((n + 1) * (n + 1) * (n + 1), -1);

	int ans = solve(s, 0, n, k, n, memo);

	printf("%d\n", ans);

	return 0;
}

/* waffle */
