#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define rep(pos, len) for(int pos=0;pos<len;pos++)
#define repp(pos, len) for(int pos=1;pos<=len;pos++)

#define INF 987654321
#define IINF 2987654321987654321
#define MOD 998244353

const int MAXN = 1e5 + 50;
ll d[MAXN], pa[MAXN], sz[MAXN], depth[MAXN];
vector<int> adj[MAXN];
int n;

bool check(int root) {
	queue<int> que;
	que.push(root);
	ll sum = 0;
	depth[root] = 0;
	while(!que.empty()) {
		int v = que.front(); que.pop();
		for(auto c : adj[v]) {
			depth[c] = depth[v] + 1;
			sum += depth[c];
			que.push(c);
		}
	}
	return sum == d[root];
}


int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &d[i]);

	map<ll, int> M;
	for(int i = 1; i <= n; i++)
		M[d[i]] = i;
	for(int i = 1; i <= n; i++)
		sz[i] = 1;

	vector<int> v;
	for(int i = 1; i <= n; i++) v.push_back(i);
	sort(v.begin(), v.end(), [](int i, int j){ return d[i] > d[j]; });
	int root = v.back();
	for(auto c : v) {
		if(c == root) break;
		ll dval = d[c] + 2*sz[c] - n;
		if(M.find(dval) == M.end() || M[dval] == c) {
			printf("-1");
			exit(0);
		}
		int p = M[dval];
		adj[p].push_back(c);
		pa[c] = p;
		sz[p] += sz[c];
	}

	if(!check(root)) {
		printf("-1");
		exit(0);
	}

	for(int i = 1; i <= n; i++)
		if(i != root) printf("%d %d\n", i, pa[i]);
}