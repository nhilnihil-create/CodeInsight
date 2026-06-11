#include <bits/stdc++.h>
using namespace std;
#define MAX_V 100001
typedef long long ll;

vector<ll> G[MAX_V]; // グラフ
ll color[MAX_V]; // 頂点iの色(1 or -1)
ll b = 0, w = 0;
// 頂点を1と-1で塗っていく
bool dfs(ll v, ll c) {
	color[v] = c; // 頂点vをcで塗る
	if (c == 1) b++;
	if (c == -1) w++;
	for (int i = 0; i < G[v].size(); i++) {
		// 隣接している頂点が同じ色ならfalse
		if (color[G[v][i]] == c) return false;
		// 隣接している頂点がまだ塗られていないなら-cで塗る
		if (color[G[v][i]] == 0 && !dfs(G[v][i], -c)) return false;
	}
	// すべての頂点を塗れたらtrue
	return true;
}

void solve(long long N, long long M, vector<long long> A, vector<long long> B){
	if (!dfs(0, 1)) printf("%lld\n", max(N*(N-1)/2-M,0LL)); else printf("%lld\n", max(b*w-M,0LL));
}

int main(){
	long long N;
	long long M;
	scanf("%lld",&N);
	scanf("%lld",&M);
	vector<long long> B(M-1+1);
	vector<long long> A(M-1+1);
	for(int i = 0 ; i <= M-1 ; i++){
		scanf("%lld",&A[i]);
		scanf("%lld",&B[i]);
		G[A[i]-1].push_back(B[i]-1);
		G[B[i]-1].push_back(A[i]-1);
	}
	solve(N, M, A, B);
	return 0;
}
