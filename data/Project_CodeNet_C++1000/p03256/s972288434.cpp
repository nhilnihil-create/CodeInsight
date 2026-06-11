#include<cstdio>
#include<vector>
using namespace std;

const int MAX_N = 200000;
char s[MAX_N+1];
vector<int> G[MAX_N];
bool valid[MAX_N];
int a_deg[MAX_N];
int b_deg[MAX_N];

void invalidate(int v) {
	valid[v] = false;
	for(int i=0;i<G[v].size();i++) {
		int u = G[v][i];
		if(valid[u]) {
			if(s[v] == 'A') a_deg[u]--;
			else b_deg[u]--;
			if(a_deg[u] == 0 || b_deg[u] == 0) invalidate(u);
		}
	}
}

void add_edge(int u, int v) {
	G[u].push_back(v);
	if(s[v] == 'A') a_deg[u]++;
	else b_deg[u]++;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	scanf("%s", s);
	for(int i=0;i<m;i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--; b--;
		add_edge(a, b);
		add_edge(b, a);
	}
	for(int i=0;i<n;i++) valid[i] = true;
	for(int i=0;i<n;i++) if(valid[i]) {
		if(a_deg[i] == 0 || b_deg[i] == 0) invalidate(i);
	}
	bool empty = true;
	for(int i=0;i<n;i++) if(valid[i]) empty = false;
	printf("%s\n", empty ? "No" : "Yes");
	return 0;
}
