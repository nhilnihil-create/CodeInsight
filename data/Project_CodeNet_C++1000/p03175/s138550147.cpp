#include<iostream>
#include<cstdio>
#include<cstring>
#include <fstream>
#include<string>
#include<sstream>
#include<algorithm>
#include<bitset>
#include<vector>
#include<deque>
#include<queue>
#include<list>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<iomanip>
#include <functional>
#include <math.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const long long int MOD = 1000000007;
const int INF = 1000000007;
const double EPS = 1e-10;
const double PI = 3.14159265359;
const int N = 100005;
//cout << fixed << std::setprecision(9)
//--------------------------

ll dp[N][2];
vector<int> edge[N];
int n, u, v;

void dfs(int x, int last)
{
	dp[x][0] = dp[x][1] = 1;
	for (auto to : edge[x]) {
		if (to == last) continue;
		dfs(to, x);
		dp[x][0] = dp[x][0] * ((dp[to][0] + dp[to][1]) % MOD) % MOD;
		dp[x][1] = dp[x][1] * dp[to][0] % MOD;
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}

	dfs(1, -1);
	cout << (dp[1][0] + dp[1][1]) % MOD << endl;

	return 0;
}
