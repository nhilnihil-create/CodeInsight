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

int a[305][305];
int rec1[90005];
int rec2[90005];
int dist[90005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int h, w, d;
	cin >> h >> w >> d;
	rep(i, h)rep(j, w) {
		cin >> a[i][j];
		rec1[a[i][j]] = i, rec2[a[i][j]] = j;
	}
	for (int i = d + 1; i <= h * w; ++i)
		dist[i] = dist[i - d] + abs(rec1[i] - rec1[i - d]) + abs(rec2[i] - rec2[i - d]);
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		printf("%d\n", dist[r] - dist[l]);
	}
	return 0;
}
