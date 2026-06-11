#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep_lr(i,l,r) for(int i=(l);i<(r);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
constexpr int INF = INT_MAX >> 1;
constexpr ll LINF = 5000000000000000LL;
constexpr int MOD = 1000000007;

int main() {

	int n, m, c;
	cin >> n >> m >> c;
	vvi a(n, vi(m));
	vi b(m);
	rep(i, m)cin >> b[i];
	rep(i, n)rep(j, m)cin >> a[i][j];
	int ans = 0;
	rep(i, n) {
		int d = c;
		rep(j, m)d += a[i][j] * b[j];
		if (d > 0)ans++;
	}
	cout << ans << endl;

}