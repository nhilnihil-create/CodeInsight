#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define sz(s) (int)s.size()

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    int a[2000], b[2000];
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> b[i];
    int mx = *max_element(a, a + n);
    int my = *min_element(b, b + m);
    for (int i = x + 1; i <= y; ++i)
    if (mx < i && i <= my) {
        cout << "No War\n";
        return 0;
    }
    cout << "War\n";
}