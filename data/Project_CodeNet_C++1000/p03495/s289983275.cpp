#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main() {
    int n, k, a[201010];
    cin >> n >> k;
    rep(i, n) cin >> a[i];

    // 数字の種類を数える
    map<int, int> cnt;
    rep(i, n) cnt[a[i]]++;

    // 数字の種類の数だけを配列にして少ない順にする
    vector<int> v;
    for (auto p : cnt) v.push_back(p.second);
    sort(v.begin(), v.end());

    // 種類数
    int size = v.size();

    // 種類が最初からK種類以下なら変える必要がないので0
    if (size <= k) {
        printf("0\n");
    } else {
        // それ以外の場合では、数の種類から条件種類を引いて、その差の分、種類の数の配列から変更する個数をansに入れる
        int ans = 0;
        rep(i, size - k) ans += v[i];
        printf("%d\n", ans);
    }
    return 0;
}