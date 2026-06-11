#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define reps(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define rreps(i, n) for (int i = ((int)(n)); i > 0; --i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define repc2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define inf 2e9
#define linf 9000000000000000000ll
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int n, m, q, l, r;
int sum[501][501];

int main() {
    scanf("%d%d%d", &n, &m, &q);
    rep(i, m) {
        scanf("%d%d", &l, &r);
        sum[l][r]++;
    }
    reps(i, n) {
        reps(j, n) { sum[i][j] += sum[i][j - 1]; }
    }
    reps(i, n) {
        reps(j, n) { sum[i][j] += sum[i - 1][j]; }
    }
    rep(i, q) {
        scanf("%d%d", &l, &r);
        printf("%d\n", sum[r][r] - sum[r][l - 1] - sum[l - 1][r] + sum[l - 1][l - 1]);
    }
    return 0;
}