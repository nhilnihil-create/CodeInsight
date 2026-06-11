#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
// Welcome to my source code!
// わけわからん

const int INF = 1001001001;

int main() {
    int n;
    cin >> n;
    P red[n], blue[n];
    for (int i = 0, a, b; i < n; i++) {
        cin >> a >> b;
        red[i] = { a, b };
    }
    for (int i = 0, c, d; i < n; i++) {
        cin >> c >> d;
        blue[i] = { c, d };
    }
    sort(blue, blue + n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        P t = { -1, -1 };
        int idx = -1;
        for (int j = 0; j < n; j++) {
            if (red[j].first >= blue[i].first || red[j].second >= blue[i].second) continue;
            if (t.second < red[j].second) {
                t = red[j];
                idx = j;
            }
        }
        if (idx == -1) continue;
        red[idx] = { INF, INF };
        ans++;
    }
    cout << ans << endl;
}