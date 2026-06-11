#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    int a[h][w];
    rep(i, h) rep(j, w) cin >> a[i][j];

    int ans = 0;
    vector<int> v;

    rep(i, h) rep(j, w) {
        if (a[i][j] % 2 == 1) {
            if (j == w - 1 && i == h - 1) continue;

            v.push_back(i + 1);
            v.push_back(j + 1);
            if (j < w - 1 && a[i][j + 1] % 2 == 1) {
                v.push_back(i + 1);
                v.push_back(j + 2);
                a[i][j]--, a[i][j + 1]++;
            } else if (i < h - 1 && a[i + 1][j] % 2 == 1) {
                v.push_back(i + 2);
                v.push_back(j + 1);
                a[i][j]--, a[i + 1][j]++;
            } else if (j < w - 1) {
                v.push_back(i + 1);
                v.push_back(j + 2);
                a[i][j]--, a[i][j + 1]++;
            } else if (i < h - 1) {
                v.push_back(i + 2);
                v.push_back(j + 1);
                a[i][j]--, a[i + 1][j]++;
            }
            ans++;
        }
    }

    cout << ans << endl;
    for (int i = 1; i <= v.size(); i++) {
        cout << v[i - 1];
        if (i != 1 && i % 4 == 0)
            cout << endl;
        else
            cout << ' ';
    }
    return 0;
}
