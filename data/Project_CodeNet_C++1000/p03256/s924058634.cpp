
#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
#define f(i,a,b) for (int i = a; i < b; i++)
#define pb push_back

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	clock_t start = clock();
#endif

	int n,m;
	cin>>n>>m;
	string s; cin>>s;
	vi adj[n];
	int p[n][2];
	f(i,0,n) p[i][0] = p[i][1] = 0;
	f(i,0,m) {
		int a,b;
		cin>>a>>b;
		adj[--a].pb(--b);
		adj[b].pb(a);
		p[a][s[b]-'A']++;
		p[b][s[a]-'A']++;
	}
	vi pq;
	vi marked(n,0);
	f(i,0,n) if (!p[i][0] || !p[i][1]) {
		pq.pb(i);
		marked[i] = 1;
	}
	while (pq.size()) {
		int v = pq.back(); pq.pop_back();	
		for (int w : adj[v]) if (!marked[w] && !--p[w][s[v]-'A']) {
			pq.pb(w);
			marked[w] = 1;
		}
	}
	bool found = 0;
	f(i,0,n) if (!marked[i]) found = 1;
	cout << (found?"Yes":"No") << endl;

#ifdef LOCAL
	cout << setprecision(12) << (long double)(clock()-start) / CLOCKS_PER_SEC << endl;
#endif
	
	return 0;
}

