#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S.at(i);

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S.at(i).at(j) == '.') {
                int count = 0;
                for (int k = max(i - 1, 0); k <= min(i + 1, H - 1); k++) {
                    for (int l = max(j - 1, 0); l <= min(j + 1, W - 1); l++) {
                        if (S.at(k).at(l) == '#') count++;
                    }
                }
                S.at(i).at(j) = '0' + count;
            }
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << S.at(i).at(j);
            if (j == W - 1) cout << endl;
        }
    }
}
