#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define vi vector<int>
#define sz(a) (int((a).size()))
#define mp make_pair
#define f first
#define s second
#define pii pair<int, int>

using namespace std;

const int N = 200200;
int n, m;
vi g[N];
bool ok[N], col[N], del[N];
int a[2][N], used[N];
queue<int> q;
string ans[2] = {"No", "Yes"};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	string s;
	cin >> s;
	for (int i = 1; i <= n; i++)
		col[i] = s[i - 1] == 'B';
	
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		if (x == y) {
			ok[x] = 1;
			a[col[x]][x]++;
		} else {
			a[col[y]][x]++;
			a[col[x]][y]++;
			g[x].pb(y);
			g[y].pb(x);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (!(a[0][i] && a[1][i])) {
			q.push(i);
		        del[i] = 1;
		}
	}
	
	
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int i = 0; i < sz(g[v]); i++) {
			int to = g[v][i];
			if (!del[to]) {
				a[col[v]][to]--;
				if (!(a[0][to] && a[1][to])) {
					del[to] = 1;
					q.push(to);
				}
			}
		}
	}
	
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cnt += !del[i];
	}
	
	cout << ans[cnt > 0] << "\n";
	
	return 0;
}
