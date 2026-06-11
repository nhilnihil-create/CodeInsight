#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
using ll = long long;
template <class T>
inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}
const int inf = 1e9; //1(1倍)e(指数)9(10^9)
int main() {
    int n;
    scanf("%d", &n);

    ll h[100010];
    rep(i, n) scanf("%lld", &h[i]);

    ll dp[100010];
    // 初期化 (最小化問題なので INF に初期化)
    rep(i, 100010) dp[i] = inf;

    // 初期条件 足場0からスタートするので、スタート時点でのコストは0
    dp[0] = 0;

    // [i-2] [i-1] i の3つの足場で考えて、iに行く最小のコストを導く
    // 仮定として「ノード i−2 やノード i−1 までの最適な進み方はわかっている」とする
    // i−1 から遷移して来た場合: dp[ i - 1 ] + abs( h[ i ] - h[ i - 1 ] )、 i−2 から遷移して来た場合: dp[ i - 2 ] + abs( h[ i ] - h[ i - 2 ] )
    // chmin は change minimum = a より b の方が小さかったら、a の値を b の値に置き換える (そして true を返す) そうでなかったら、何もしない (そして false を返す)
    // 各 i=1,2,…,N−1i=1,2,…,N−1 に対して順にループを回していけば、dp[ 1 ], dp[ 2 ], dp[ 3 ], ... の値が順々に決まって行く
    for (int i = 1; i < n; ++i) {
        chmin(dp[i], dp[i - 1] + abs(h[i] - h[i - 1]));
        if (i > 1) chmin(dp[i], dp[i - 2] + abs(h[i] - h[i - 2])); //2個以上になってはじめて1個飛ばしができる
    }

    printf("%lld\n", dp[n - 1]);
}