#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = (1ll << 61);
const int inf = 1001001001;
const int mod = 1000000007;

vector<int> g[100005];
int n;

vector<int> res;
void dfs(int v, int p = -1, int cnt = 0) {
	res[v] = cnt;
	for (int c : g[v]) {
		if (c == p) continue;
		dfs(c, v, cnt + 1);
	}
}

vector<int> distcalc(int a) {
	res = vector<int>(n);
	dfs(a);
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, h, w;
	cin >> n >> h >> w;
	int ans = 0;
	while (n--) {
		int a, b;
		cin >> a >> b;
		if (a >= h && b >= w) ans++;
	}
	cout << ans << endl;
	return 0;
}
