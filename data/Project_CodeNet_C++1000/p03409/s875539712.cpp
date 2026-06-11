#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> red(n), blue(n);
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        red[i] = make_pair(a, b);
    }
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        blue[i] = make_pair(a, b);
    }

    sort(blue.begin(), blue.end());

    vector<bool> used(n, false);
    int cnt = 0;
    rep(i, n) {
        int bx = blue[i].first, by = blue[i].second;

        int near_y = -1000, near_j = -1;
        rep(j, n) {
            if (used[j]) continue;

            int rx = red[j].first, ry = red[j].second;
            if (rx > bx) continue;
            if (ry > by) continue;

            if (ry > near_y) {
                near_j = j;
                near_y = ry;
            }
        }
        if (near_j != -1) {
            cnt++;
            used[near_j] = true;
        }
    }
    cout << cnt << endl;
}