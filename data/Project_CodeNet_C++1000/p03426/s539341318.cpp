#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//累積和の問題
//R-L % D == 0であるから，R%D ≡ L%D = xとおく
//クエリは，（xからRに行くためにかかるコスト）-（xからLに行くためにかかるコスト）に単純化される
//即ち，y = 0~D-1において，xからyまでDずつ移動するのにかかるコストをtableで保持し，table[x][y]をもとにクエリ処理する
//計算量は，(D*(H*W) + Q)で，十分間に合う

int H, W, D;
vector<pair<int, int>> idx;
vector<int> memo;

int f(int x) {
    if (0 < memo[x]) return memo[x];
    if (x < D) return 0;
 
    int y = x - D;
    int cost = abs(idx[x].first - idx[y].first) + abs(idx[x].second - idx[y].second);
    int res = cost + f(y);
    return memo[x] = res;
}

int main() {
    cin >> H >> W >> D;
    idx.resize(H*W);
    memo.assign(H*W, -1);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int a; cin >> a; a--;
            idx[a] = make_pair(i, j);
        }
    }
    int Q; cin >> Q;
    for (int i = 0; i < Q; i++) {
        int L, R; cin >> L >> R; L--; R--;
        int dist = f(R)-f(L);
        cout << dist << endl;
    }
}