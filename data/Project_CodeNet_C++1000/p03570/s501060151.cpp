#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <cstring>
#include <cmath>
#include <stack>
#include <iomanip>
#include <tuple>
#include <functional>

//#define int long long
#define CONTAINS(v,n) (find((v).begin(), (v).end(), (n)) != (v).end())
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
#define ARY_SORT(a, size) sort((a), (a)+(size))
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define REMOVE(v,a) v.erase(remove(v.begin(), v.end(), a), v.end())
#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define REPE(i, n) for (int (i) = 0; (i) <= (n); (i)++)
using namespace std;

char S[200001];
int dp[67108865];

int MAX_VAL = 1000000000;

signed main()
{
	cin >> S;
	REP(i, 67108865) dp[i] = MAX_VAL;
	dp[0] = 0;
	int N = strlen(S);
	int c = 0;
	for (int i = 0; i < N; i++)
	{
		c ^= (1 << (S[i] - 'a'));
		int min = dp[c];
		for (int j = 0; j < 26; j++)
		{
			min = MIN(min, dp[c ^ (1 << j)]);
		}
		dp[c] = MIN(dp[c], min + 1);
	}
	cout << MAX(1, dp[c]) << endl;
}