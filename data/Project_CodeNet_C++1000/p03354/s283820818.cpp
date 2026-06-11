#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 1e5+10;
int N, M;
int p[MAX_N];
int x[MAX_N], y[MAX_N];
int par[MAX_N];

int look(int x)
{
	if(x == par[x]) return x;
	else return par[x]=look(par[x]);
}

void comb(int x, int y)
{
	int a=look(x), b=look(y);
	if(a!=b){
		par[a]=b;
	}
}

void solve()
{
	for(int i=1;i<=N;++i) par[i]=i;
	for(int i=0;i<M;++i){
		comb(x[i], y[i]);
	}
	int ans = 0;
	for(int i=1;i<=N;++i){
		if(i == p[i] || (look(i)==look(p[i]))) ans++;
	}
	cout << ans << '\n';
} 

int main()
{
	cin >> N >> M;
	for(int i=1;i<=N;++i) cin >> p[i];
	for(int i=0;i<M;++i) cin >> x[i] >> y[i];
	solve();
	return 0;
}