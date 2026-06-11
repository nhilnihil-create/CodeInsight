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

#define MAX_N 500
vector<int> to[MAX_N + 1];

int n, m, q;

int main() {
    cin >> n >> m >> q;
    int l, r;
    rep(i, m) {
        scanf("%d%d", &l, &r);
        to[l].push_back(r);
    }
    reps(i, n) { sort(all(to[i])); }
    rep(i, q) {
        scanf("%d%d", &l, &r);
        int ans = 0;
        repc2(j, l, r) { ans += (int)(upper_bound(all(to[j]), r) - to[j].begin()); }
        printf("%d\n", ans);
    }
    return 0;
}