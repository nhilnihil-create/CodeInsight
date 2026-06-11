#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 100005;
int p[N];

int find(int v){
	return (p[v] < 0)?v:(p[v] = find(p[v]));
}

ll combine(int u, int v){
	u = find(u);
	v = find(v);
	if(u == v)return 0;
	ll ret = p[u]*1LL*p[v];
	if(p[u] > p[v])swap(u, v);
	p[u] += p[v];
	p[v] = u;
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n, m;
	cin>>n>>m;
	vector<int> a(m), b(m);
	for(int i = 0; i < m; i++){
		cin>>a[i]>>b[i];
	}
	memset(p, -1, sizeof(p));
	vector<ll> ans(m);
	ll cur = n*1LL*(n - 1)/2;
	for(int i = m - 1; i >= 0; i--){
		ans[i] = cur;
		cur -= combine(a[i], b[i]);
	}
	for(auto x : ans){
		cout<<x<<'\n';
	}

	return 0;
}