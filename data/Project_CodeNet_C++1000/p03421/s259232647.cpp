#include <bits/stdc++.h>
using namespace std;

const int maxn = 300002;

int n, A, B, p[maxn];

int main() {
    //freopen("lisdl.inp", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> A >> B;
    if (n<A+B-1 || 1LL*A*B<n) {
        cout << -1;
        return 0;
    }
    p[1] = B;
    int tmp = n - B - A + 1;
    for (int i=2; i<=A; ++i) {
        p[i] = 1;
    }
    for (int i=2; i<=A; ++i) {
        p[i] += min(tmp, B-1);
        tmp -= min(tmp, B-1);
    }
    int cur = 1;
    for (int i=1; i<=A; ++i) {
        for (int j=p[i]-1; j>=0; --j)
            cout << cur + j << ' ';
        cur += p[i];
    }
}
