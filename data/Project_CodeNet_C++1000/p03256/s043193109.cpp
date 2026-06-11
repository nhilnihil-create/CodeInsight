#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define FORR(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, m, a, b, c[MX], x[MX][2];
char ch;
vi adj[MX];
bitset<MX> ex;
queue<int> q;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> ch;
		c[i] = ch == 'A';
		ex[i] = 1;
	}

	while (m--) {
		cin >> a >> b;
		adj[a].pb(b);
		if (a != b) adj[b].pb(a);

		x[a][c[b]]++;
		if (a != b) x[b][c[a]]++;
	}

	for (int i = 1; i <= n; i++)
		if (!x[i][0] || !x[i][1]) {
			q.push(i);
			ex[i] = 0;
		}

	while (q.size()) {
		int u = q.front();
		q.pop();

		for (int v : adj[u]) {
			x[v][c[u]]--;
			if ((!x[v][0] || !x[v][1]) && ex[v]) {
				q.push(v);
				ex[v] = 0;
			}
		}
	}

	if (ex.count()) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}