#include<bits/stdc++.h>
using namespace std;
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9	
#define MOD 1000000007
typedef pair<int, int> PII;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
typedef vector<int64> VI;
typedef vector<VI> VVI;
const int mod = 1000000007;
void printV(VVI dp) {
	for(VI k: dp) {
		for(int i: k) cout << i << " ";
			cout << endl;
	}
	cout << endl;
}
void solve() {
	int n, m;
	cin >> n >> m;
	std::vector<std::vector<char>> adj(n,std::vector<char>(m,0));

	VVI dp(n+1,VI(m+1,0));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> adj[i][j];
		}
	}
	if(adj[n-1][m-1] == '#') {
		cout << 0;
		return;
	}
	for (int i = n-1; i >= 0; --i)
	{
		for (int j = m-1; j >= 0; --j)
		{
			if(adj[i][j] == '#') continue;
			if(i == n-1 && j == m-1) {
				dp[i][j] = 1;
				continue;
			}
			int64 left = j < m ? dp[i][j+1]%mod:0;
			int64 down = i < n? dp[i+1][j]%mod:0;

			int64 ans = (left+down)%mod;
			dp[i][j] = ans;
		}
	}
	// printV(dp);
	cout << dp[0][0];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();

	return 0;
}