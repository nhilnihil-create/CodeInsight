#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 1e5+2;
int N, M;
int A[MAX_N], B[MAX_N];
ll ans[MAX_N];
int par[MAX_N], sz[MAX_N];

int look(int x)
{
	if(par[x] == x) return x;
	else return par[x] = look(par[x]);
}

void comb(int x, int y)
{
	int a = look(x), b = look(y);
	if(a != b){
		par[a] = b;
		sz[b] += sz[a];
	}
}

void solve()
{
	for(int i=1;i<=N;++i){
		par[i] = i;
		sz[i] = 1;
	}
	ll cur = 1LL*N*(N-1)/2;
	for(int i=M-1;i>=0;--i){
		ans[i]=cur;
		if(look(A[i])!=look(B[i])){
			const ll n = 1LL*sz[par[A[i]]]*sz[par[B[i]]];
			cur -= n;
		}
		comb(A[i],B[i]);
	}	
	for(int i=0;i<M;++i) cout << ans[i] << '\n';
}

int main()
{
	cin >> N >> M;
	for(int i=0;i<M;++i) cin >> A[i] >> B[i];
	solve();
	return 0;
}