
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, x, t, cnt;
int a[105];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> x;
    for (int i = 0; i < m; ++i) {
        cin >> t;
        ++a[t];
    }
    for (int i = x; i < n; ++i) {
        if (a[i])
            ++cnt;
    }
    int ans = cnt;
    cnt = 0;
    for (int i = x; i >= 0; --i) {
        if (a[i])
            ++cnt;
    }
    ans = min(ans, cnt);
    cout << ans << endl;

    return 0;
}

