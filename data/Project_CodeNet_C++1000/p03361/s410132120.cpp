#include <bits/stdc++.h>
using namespace std;

int main() {

    int H, W;
    cin >> H >> W;

    vector<string> S(H);
    for (int i = 0; i< H; i++) {
        cin >> S.at(i);
    }

    int dx[] ={ -1, 0, 0, 1 };
    int dy[] ={ 0, -1, 1, 0 };

    int x;
    int y;
    bool ok = true;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S.at(i).at(j) != '#') {
                continue;
            }

            for (int k = 0; k < 4; k++) {
                ok = false;
                x = i + dx[k];
                y = j + dy[k];
                if (x >= 0 && x < H && y >= 0 && y < W) {
                    if (S.at(x).at(y) == '#') {
                        ok = true;
                        break;
                    }
                }
            }

            if (!ok) {
                break;
            }
        }

        if (!ok) {
            break;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;

    return 0;
}