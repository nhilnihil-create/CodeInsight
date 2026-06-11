#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int h, w; cin >> h >> w;
    vector<vector<char>> c(h + 2, vector<char>(w + 2));
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> c[i][j];
        }
    }

    bool can = true;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (c[i][j] == '#') {
                if (c[i - 1][j] == '#' || c[i + 1][j] == '#' || c[i][j - 1] == '#' || c[i][j + 1] == '#') {
                }
                else { 
                    can = false;
                }
            }
        }
    }

    if (can) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}