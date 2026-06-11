// ※※※ ロジック見直し ※※※
// ryoissy氏.
// https://atcoder.jp/contests/cf17-final/submissions/1803042
#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
#define rep(i, n) for(int i = 0; i < n; i++)
#define a first
#define b second
int n, d[51];
P p[51];
int gg[51];

int main(){
    scanf("%d",&n);
    rep(i, n){
        scanf("%d", d + i);
        p[i] = P(abs(12 - d[i]), d[i]);
    }
    p[n] = P(12, 0);
    sort(p, p + n + 1);
    int s = 1;
    rep(i, n + 1){
        if(s == 1) gg[i] = min(p[i].b, 24 - p[i].b);
        else       gg[i] = max(p[i].b, 24 - p[i].b);
        s = 1 - s;
    }
    sort(gg, gg + n + 1);
    int diff = 24;
    rep(i, n) diff = min(diff, gg[i + 1] - gg[i]);
    diff = min(diff, 24 - gg[n] + gg[0]);
    printf("%d\n", diff);
    return 0;
}