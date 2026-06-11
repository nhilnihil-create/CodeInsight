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

int h, w, sum;
int c[10][10];
int M[200][200];

int main() {
    cin >> h >> w;
    rep(i, 10) rep(j, 10) cin >> c[i][j];
    rep(i, h) rep(j, w) cin >> M[i][j];
    rep(k, 10) rep(i, 10) rep(j, 10) c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
    rep(i, h) rep(j, w) if (M[i][j] != -1) sum += c[M[i][j]][1];
    cout << sum << endl;
    return 0;
}