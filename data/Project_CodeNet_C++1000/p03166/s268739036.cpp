#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef long int				int32;
typedef unsigned long int		uint32;
typedef long long int			int64;
typedef unsigned long long int  uint64;
typedef pair<int, int>			PII;
typedef vector<int>				VI;
typedef vector<long long>		VLL;
typedef vector<string>			VS;
typedef vector<PII>				VII;
typedef vector<VI>				VVI;

#define MEM(a, b)				memset(a, (b), sizeof(a))
#define calctime				std::cout << setprecision(5) << fixed << "Time to completed program: " << (double)(clock() - start)/(CLOCKS_PER_SEC) << "s.\n";
#define FOR(i, j, k, in)		for (int i = (j); i < (k); i += (in))
#define FORW(i, j, k, in)		for (int i = (j); i <= (k); i += (in))
#define RFOR(i, j, k, in)		for (int i = (j); i >= (k); i -= (in))
#define RFORW(i, j, k, in)		for (int i = (j); i > (k); i -= (in))
#define aint64(cont)			cont.begin(), cont.end()
#define raint64(cont)			cont.end(), cont.begin()
#define sz(cont)				int((cont).size())
#define PB						push_back
#define MP						make_pair
#define EPS						1e-9
#define MOD						1000000007
#define PI						3.1415926535897932384626433832795
#define Ff						first
#define Ss						second
#define FastIO					ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
#define fileIO(name)			ifstream iFs(name".inp"); ofstream oFs(name".out");
#define fileio(name)			ifstream cin(name".inp"); ofstream cout(name".out");
#define endl					'\n'

//int dx[] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[] = {0, -1, 0, 1, 1, -1, -1, 1};	

VI adj[100006] = {};
int dp[100006] = {};
bool used[100006] = {};

void dfs(int u) {
	used[u] = 1;
	FOR(i, 0, adj[u].size(), 1) {
		int v = adj[u][i];
		if (!used[v])
			dfs(v);
		dp[u] = max(dp[u], 1 + dp[v]);
	}
}

int main() {
	FastIO;

	int n, m; cin >> n >> m;
	FOR(i, 0, m, 1) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
	}
	
	int ans = 0;
	FORW(i, 1, n, 1) {
		if (!used[i])
			dfs(i);
	}
	FORW(i, 1, n, 1) ans = max(ans, dp[i]);
	cout << ans << endl;

	//calctime
	return 0;
}