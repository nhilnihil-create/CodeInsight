#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    int l[100000], r[100000];
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> l[i] >> r[i];

    sort(l, l + m, greater<>());
    sort(r, r + m);
    int ans = r[0] - l[0] + 1;
    if (ans < 0) ans = 0;
    cout << ans << endl;
}
