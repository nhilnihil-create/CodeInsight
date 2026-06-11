#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
using ll = long long;
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int p[100000], y[100000];
    vector<int> yd[100001];
    rep(i, m) {
        scanf("%d%d", &p[i], &y[i]);
        yd[p[i]].push_back(y[i]);
    }
    rep(i, n) sort(yd[i + 1].begin(), yd[i + 1].end()); //ydの添字pが1スタートだから+1してる。県の数n回繰り返す。
    // %0桁数d
    // lower_bound(yd[p[0]].begin(), yd[p[0]].end(), y[0]) は、探索したい値y[0]以上が現れる最初の位置のイテレータを取得。イテレータなので+1してる
    rep (i, m) {
        printf("%012lld\n", ll(p[i]) * 1000000 + int(lower_bound(yd[p[i]].begin(), yd[p[i]].end(), y[i]) - yd[p[i]].begin()) + 1);
    }
    return 0;
}
