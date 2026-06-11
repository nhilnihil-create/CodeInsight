#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> cnt(m, 0); //m個の要素、0で初期化
    rep(i, n) {
        int k;
        scanf("%d", &k);
        rep(j, k) {
            int a;
            scanf("%d", &a);
            cnt[a - 1]++; //iについてそれを好きだと答えた人数をカウントしてく
        }
    }
    int ans = 0;
    rep(i, m) {
        if(cnt[i] == n) { //人数とカウント数が一緒だったら
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}