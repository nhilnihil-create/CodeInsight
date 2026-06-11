// fest
#include <bits/stdc++.h>	

#define pb push_back
#define F first
#define S second
#define y1 dasdasfasfas
#define x1 wqdadfasfasfas
#define All(c) c.begin(), c.end()
#define SZ(A) (int((A).size()))
#define umap unordered_map
#define __ fflush(stdout)
#define FILENAME ""

typedef long long ll;
typedef long double ld;    

using namespace std;

void FREOPEN() {
	#ifdef LOCAL
		freopen(".in", "r", stdin);
		freopen("1.out", "w", stdout);
	#else
		//freopen(FILENAME".in", "r", stdin);
		//freopen(FILENAME".out", "w", stdout);
	#endif
}

inline double Time() {return (clock() * 1.0) / CLOCKS_PER_SEC; }             

const int N = 20500, inf = 1e9 * 2;

const ll MOD = 1e9 + 7ll, INF = 1e18;

const int dx[] = {1, -1, 0, 0, -1, 1, -1, 1};
const int dy[] = {0, 0, 1, -1, -1, 1, 1, -1};

ll dp[N];

int w[N], s[N], v[N];

int main() {
	FREOPEN();
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) 
		scanf("%d %d %d", &w[i], &s[i], &v[i]);
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (w[i] + s[i] > w[j] + s[j]) {
				swap(w[i], w[j]), swap(s[i], s[j]), swap(v[i], v[j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = s[i]; j >= 0; j--) {
			dp[j + w[i]] = max(dp[j + w[i]], dp[j] + v[i]);
 		}
	}
	ll ans = 0;
	for (int i = 0; i < N; i++) ans = max(ans, dp[i]);
	printf("%lld", ans);
	return 0;
}
