#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#define fastIO() ios_base::sync_with_stdio(0), cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ms(a, x) memset(a, x, sizeof(a))
#define len(x) (x).size()
#define pb push_back
#define eb emplace_back
#define f first
#define s second

const double eps = 1e-9;
const double pi = acos(-1.0);
const int inf = 1e9;
const int maxn = 1e3+5;
const int mod = 1e9 + 7;

int n, k;
int c[maxn];
int dp[maxn][100005];

int main() {
    fastIO();
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> c[i];
   	dp[n][0] = 1;
    for (int idx = n - 1; idx >= 0; --idx) {
    	int cur = 0;
    	for (int sum = 0; sum <= k; ++sum) {
    		cur = (cur + dp[idx + 1][sum]) % mod;
    		if (sum >= c[idx]) 
    			cur = (cur - dp[idx + 1][sum - c[idx] - 1] + mod) % mod;
    		dp[idx][sum] = cur;
    		/*
			for (int i = 0; i <= c[idx]; ++i) {
				if (sum + i > k) break;
				ans = (ans + solve(idx + 1, sum + i)) % mod;
			}
			*/
    	}
    }
    cout << dp[0][k] << '\n';
    //cout << solve(0, 0) << '\n';
    return 0;
}

