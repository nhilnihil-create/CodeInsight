#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
using ll = long long;
int main() {
    int n;
    scanf("%d", &n);

    vector<int> a(n), b(n), c(n);
    rep(i, n) scanf("%d", &a[i]);
    rep(i, n) scanf("%d", &b[i]);
    rep(i, n) scanf("%d", &c[i]);

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    ll ans = 0;
    rep(i, n) {
        // bをiで固定して、bより小さくなるaの数とbより大きくなるcの数を掛け合わせる
        //そのまま全探索すると10^9*10^9とかでオーバーフローしちゃう
        // lower_boundは、ソートされた配列内で、key以上の要素の内の一番左側のイテレータを返す
        ll first = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        // upper_boundは、ソートされた配列内で、keyより大きい要素の内の一番左側のイテレータを返す
        ll third = c.end() - upper_bound(c.begin(), c.end(), b[i]);
        ans += first * third;
    }

    printf("%lld\n", ans);
    return 0;
}