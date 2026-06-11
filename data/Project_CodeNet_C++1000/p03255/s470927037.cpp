#include"bits/stdc++.h"
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
const long long mod = 1000000007;
const long long inf = 1ll << 61;
typedef pair<int, int> P;
typedef pair<int, P> PP;
typedef pair<int, PP> PPP;
struct edge { int to;  int cost; };
int x[200006];
int rwa[200006];
vector<int>G[200006];
vector<int>V;
signed main() {
	int n, X; cin >> n >> X;
	rep(i, n)cin >> x[i];
	rep(i, n)rwa[i + 1] = x[i];
	rep(i, n)rwa[i + 1] += rwa[i];
	int ans = inf;
	int s1 = 0;

	for(int i=1;i<=n;i++){//i台
		int sum = i*X + n*X;
		s1 += x[n - i]*5;
		sum += s1;
		
		for (int j = n - 1; j >= 0; j -= i) {
			int r = j, l = j - i + 1;
			l = max(l, 0ll);
			int p = (n - 1 - j) / i;
			if (p) {
				p = 2 * p + 3;
				sum += p*(rwa[r + 1] - rwa[l]);
			}
		}
		if (sum < 0)sum = inf;
		ans = min(ans, sum);
	}
	cout << ans << endl;
}