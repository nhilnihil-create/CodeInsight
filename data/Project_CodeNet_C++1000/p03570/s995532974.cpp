// ※※※ 解答不能 ※※※
// Factorio氏.
// https://atcoder.jp/contests/code-festival-2017-qualc/submissions/1701367
#include <bits/stdc++.h>
using namespace std;
int d[(1 << 26) + 7];
char s[200020];
int main(){
    memset(d, 0x3f, sizeof d);
    scanf("%s", s);
    int n = strlen(s), b = 0, t = 0;
    d[0] = 0;
    for(int i = 0; i < n; i++){
        b ^= (1 << (s[i] - 'a'));
        t = d[b];
        for(int j = 0; j < 26; j++) t = min(t, d[b ^ (1 << j)]);
        d[b] = min(d[b], t + 1);
    }
    printf("%d\n", max(d[b], 1));
    return 0;
}