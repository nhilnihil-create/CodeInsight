#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rep(i, l, r) for(int i = (l); i < (r); ++i)
#define dd(x) cout << #x << " = " << x << ", "
#define de(x) cout << #x << " = " << x << endl
//-------
const int N = 2020;
int n, m, q;
int a[N];
bool vis[N];
vector<vi> b;
int main() {
	scanf("%d%d%d", &n, &m, &q);
	rep(i, 0, n) scanf("%d", a + i), b.pb({a[i], i});
	sort(all(b));
	int ans = 2e9;
	for(int l = 0, r = 0; l < sz(b); l = r) {
		vi sb;
		for(int i = 0, j = 0; i < n; i = j) {
			while(i < n && vis[i]) i++;
			j = i;
			vi b;
			while(j < n && !vis[j]) b.pb(a[j++]);
			sort(all(b));
			rep(k, 0, sz(b) - m + 1)
				sb.pb(b[k]);
		}
		sort(all(sb));
		if(sz(sb) >= q) {
			ans = min(ans, sb[q - 1] - sb[0]);
		//	dd(sb[q - 1]), de(sb[0]);
		}
		r = l;
		while(r < sz(b) && b[r][0] == b[l][0])
			vis[b[r++][1]] = 1;
		rep(i, 0, n) if(vis[i]) {
			int j = i + 1;
			while(j < n && !vis[j]) j++;
			if(j - i - 1 < m) {
				rep(_, i, j) vis[i] = 1;
			}
		}
	//	dd(l), dd(r), de(ans);
	}
	printf("%d\n", ans);
	return 0;
}

