#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INFL 0x6fffffffffffffffLL

//蟻本のコード

vector<ll> par(200001);	//要素の親
vector<ll> rnk(200001); //木の高さ(併合時に使う)
vector<ll> cnt(200001);	//ノードの数

ll find(ll x) {			//親ノードを求める
	if (par[x] == x) {
		return x;
	} else {
		return par[x] = find(par[x]);	//辺の縮約(rnkは高速化のため変えない)
	}
}

void unite(ll x , ll y) {	//ノードを併合
	x = find(x);
	y = find(y);
	if (x == y) return;
	else if (rnk[x] < rnk[y]) {
		par[x] = y;
		cnt[y] += cnt[x];
	} else {
		par[y] = x;
		cnt[x] += cnt[y];
		if (rnk[x] == rnk[y]) rnk[x]++;
	}
}

ll usize(ll x) {			//xが属するノードのサイズを求める
	return cnt[find(x)];
}

bool same(ll x, ll y) {		//xとyが同じノードか判定する
	return find(x) == find(y);
}

int main() {
	ll		i,j,m,n;

	cin >> n >> m;
	vector<ll> a(m),b(m),ans(m+1);

	//初期化
	for(i=1;i<=n;i++) {
		par[i] = i;
		rnk[i] = 0;
		cnt[i] = 1;
	}

	for(i=0;i<m;i++) {
		cin >> a[i] >> b[i];
	}

	ans[m] = n*(n-1)/2;
	for(i=m-1;i>0;i--) {
		ll t = usize(a[i]) * usize(b[i]);
		if (same(a[i],b[i])) t = 0;
		unite(a[i],b[i]);
		ans[i] = ans[i+1] - t;
	}

	for(i=1;i<=m;i++) {
		cout << ans[i] << endl;
	}

	return 0;
}
