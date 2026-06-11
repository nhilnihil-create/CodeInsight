#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
// const ll INF = 1000000000000000000LL;

using namespace std;

struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main() {
	int n,m;
	cin >> n >> m;
	UnionFind tree(n);
	vector<int> p(n);
	rep(i,n) cin >> p[i];
	rep(i,m){
		int x,y;
		cin >> x >> y;
		//0~n-1を入れるので、
		//かならずデクリメントする！！
		x--;y--;
		tree.unite(x,y);
	}
	int cnt=0;
	rep(i,n){
		if(tree.same(i,p[i]-1)) 
			cnt++;
	}
	cout << cnt << endl;
    return 0;
}
