#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long int;

//ARC090-D
//Union-Find木で各条件を検証する

vector<int> par;	//親
vector<ll> dfromp;	//親からの距離dist.from.par

ll dfr(int x) {		//根までの距離dist.from.root
	if (par[x] != x) {
		return dfromp[x] + dfr(par[x]);
	}
	else {
		return 0;
	}
}
int root(int x) {	//根
	if (par[x] == x) {
		return x;
	}
	else {
		dfromp[x] = dfr(x);
		par[x] = root(par[x]);
		return par[x];
	}
}

int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 0; i <= N; i++) {	//初期化
		par.push_back(i);
		dfromp.push_back(0);
	}
	for (int i = 0; i < M; i++) {
		int l, r, d; cin >> l >> r >> d;

		if (root(l) == root(r)) {	//同じ木にあるなら、距離の比較が可能
			if (dfr(r) != dfr(l) + d) {
				cout << "No"; return 0;//新情報によって矛盾が生じたらOUT
			}
		} else {	//違う木にあるなら、距離の比較が不能なので矛盾は生じない

			if (dfr(r) > dfr(l) + d) {
				dfromp[root(l)] = dfr(r) - dfr(l) - d;
				par[root(l)] = root(r);
			}
			else {
				dfromp[root(r)] = dfr(l) + d - dfr(r);
				par[root(r)] = root(l);
			}
		//	par[r] = l;	// l ← r として木をつなぐ
		//	dfromp[r] = d;//　辺の重みは距離
		}
	}

	cout << "Yes";
	return 0;
}
