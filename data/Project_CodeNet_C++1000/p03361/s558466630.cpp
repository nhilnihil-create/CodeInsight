#include <bits/stdc++.h>
using namespace std;

void solve() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> a(h+2, vector<char>(w+2));
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if(a[i][j] == '.') {
                continue;
            }
           bool l = (a[i][j - 1] == '#');
           bool r = (a[i][j + 1] == '#');
           bool d = (a[i + 1][j] == '#');
           bool u = (a[i - 1][j] == '#');
           if(l + r + d + u == 0) {
               cout << "No";
               return;
           }

        }
    }
    cout << "Yes";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
