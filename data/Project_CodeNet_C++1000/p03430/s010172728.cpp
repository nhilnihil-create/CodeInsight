//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
#define mem(a,v) memset((a), (v), sizeof (a))
#define enl printf("\n")
#define case(t) printf("Case #%d: ", (t))
#define ni(n) scanf("%d", &(n))
#define nl(n) scanf("%lld", &(n))
#define nai(a, n) for (int i = 0; i < (n); i++) ni(a[i])
#define nal(a, n) for (int i = 0; i < (n); i++) nl(a[i])
#define pri(n) printf("%d\n", (n))
#define prl(n) printf("%lld\n", (n))
#define pii pair<int, int>
#define pil pair<int, long long>
#define pll pair<long long, long long>
#define vii vector<pii>
#define vil vector<pil>
#define vll vector<pll>
#define vi vector<int>
#define vl vector<long long>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef cc_hash_table<int,int,hash<int>> ht;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
const double pi = acos(-1);
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const int MAXN = 3e2 + 5;
const double eps = 1e-9;
int dp[MAXN][MAXN][MAXN];
char str[MAXN];

int main() {
	scanf("%s", str);
	int n = strlen(str), k; ni(k);
	for (int i = 0; i <= k; i++) {
		for (int j = 0; j < n; j++)
			dp[i][j][j] = 1;
		for (int len = 1; len < n; len++) {
			for (int l = 0; l + len < n; l++) {
				int r = l + len;
				dp[i][l][r] = max(dp[i][l+1][r], dp[i][l][r-1]);
				if (str[l] == str[r])
					dp[i][l][r] = dp[i][l+1][r-1] + 2;
				else if (i)
					dp[i][l][r] = max(dp[i][l][r], dp[i-1][l+1][r-1] + 2);
			}
		}
	}
	pri(dp[k][0][n-1]);
	return 0;
}
