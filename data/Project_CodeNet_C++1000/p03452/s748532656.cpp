#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100001
#define INF 100000000000001

long long par[MAX_N]; // 親
long long rankuf[MAX_N]; // 木の深さ
long long diff_weight[MAX_N];
// n要素で初期化
void init(long long n) {
	for (long long i = 0; i < n; i++) {
		par[i] = i;
    rankuf[i] = 0;
		diff_weight[i] = 0;
	}
}
// 木の根を求める
long long find(long long x) {
	if (par[x] == x) {
		return x;
	} else {
		long long f = find(par[x]);
		diff_weight[x] += diff_weight[par[x]];
		return par[x] = f;
	}
}

long long weight(long long x) {
  find(x); // 経路圧縮
  return diff_weight[x];
}

long long diff(long long x, long long y) {
  return weight(y) - weight(x);
}

// xとyの属する集合を併合
void unite(long long x, long long y, long long d) {
	d += weight(x); d -= weight(y);
	x = find(x);
	y = find(y);
	if (x == y) return;
	if (rankuf[x] < rankuf[y]) {
		par[x] = y;
		diff_weight[x] = -d;
	} else {
		par[y] = x;
		diff_weight[y] = d;

		if (rankuf[x] == rankuf[y]) rankuf[x]++;
	}
}
// xとyが同じ集合に属するか否か
bool same(long long x, long long y) {
	return find(x) == find(y);
}

int main(){
	long long M;
	long long N;
	scanf("%lld",&N);
	scanf("%lld",&M);
	vector<long long> R(M-1+1);
	vector<long long> D(M-1+1);
	vector<long long> L(M-1+1);
	init(N+1);
	for(int i = 0 ; i <= M-1 ; i++){
		scanf("%lld",&L[i]);
		scanf("%lld",&R[i]);
		scanf("%lld",&D[i]);
	}
	bool flg = true;
	for(int i = 0 ; i <= M-1 ; i++){
		long long d = INF;
		if (same(L[i],R[i])) d = diff(L[i],R[i]);
		unite(L[i],R[i],D[i]);
		if (d != INF && d != D[i]) flg = false;
		// printf("%lld, %lld\n", d, D[i]);
	}
	if (flg) printf("Yes\n"); else printf("No\n");


	return 0;
}
