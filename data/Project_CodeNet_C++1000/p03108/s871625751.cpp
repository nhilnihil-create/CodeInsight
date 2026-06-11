#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// __uint128_t
const ll MOD = 1e9+7;

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

ll nc2(ll n){
    return (n*(n-1))/2;
}


int main(){
    ll N, M; cin >> N >> M;
    UnionFind tree(N);
    vector<ll> A(M), B(M), ANS(M);
    for(int i = 0; i < M; i++){
        cin >> A[i] >> B[i]; A[i]--; B[i]--;
    }
    vector<ll> S(N, 1);
    ll ans = 0;
    ANS[M-1] = 0;
    for(int i = M-1; i >= 1; i--){
        ll u = A[i], v = B[i];
        if(tree.root(u) != tree.root(v)) {
            // サイズの取得
            ll rootu = tree.root(u), rootv = tree.root(v);
            ll sizeu = S[rootu], sizev = S[rootv];
            ll size = sizeu + sizev;
            ans -= nc2(sizeu);
            ans -= nc2(sizev);
            ans += nc2(size);
            tree.unite(u, v);
            S[tree.root(u)] = S[tree.root(v)] = size;

            
        }
        ANS[i-1] = ans;
    }
    ll SUM = nc2(N);
    for(int i = 0; i < M; i++){
        cout << SUM - ANS[i] << endl;
    }

}
