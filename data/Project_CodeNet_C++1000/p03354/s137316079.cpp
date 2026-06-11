#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 100005;
int perm[N], p[N];

int find(int v){
	return (p[v] < 0)?v:(p[v] = find(p[v]));
}

void combine(int u, int v){
	u = find(u); v = find(v);
	if(u == v)return;
	if(p[u] > p[v])swap(u, v);
	p[u] += p[v];
	p[v] = u;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n, m;
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin>>perm[i];
	}
	memset(p, -1, sizeof(p));
	for(int i = 0; i < m; i++){
		int u, v;
		cin>>u>>v;
		combine(u, v);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(find(i) == find(perm[i]))ans++;
	}
	cout<<ans<<'\n';

	return 0;
}