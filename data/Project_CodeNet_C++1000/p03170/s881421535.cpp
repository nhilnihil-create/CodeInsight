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
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int, int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
int n, k, min_;
VI nums, dp;


void solve() {
	cin >> n >> k;
	nums.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	dp.resize(k+1,0);

	for(int i = 1; i <= k; i++) {
		for(int num: nums) {
			if(i-num < 0) continue;

			if(dp[i-num] == 0) {
				dp[i] = 1;
			}
		}
	}

	if(dp[k]) cout << "First";
	else cout << "Second";

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();

	return 0;
}