#include <bits/stdc++.h>
using namespace std;

int main() {

    int H, W;
    cin >> H >> W;

    vector<string> S(H);
    for (int i = 0; i< H; i++) {
        cin >> S.at(i);
    }

    int cnt = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cnt = 0;
            if (S.at(i).at(j) != '.') {
                cout << S.at(i).at(j);
                continue;
            }

            for (int k = max(i - 1, 0); k < min(H, i + 2); k++) {
                for (int l = max(j -1, 0); l < min(W, j +2); l++) {
                    if (S.at(k).at(l) == '#') {
                        cnt++;
                    }
                }
            }

            cout << cnt;
        }

        cout << "" << endl;
    }

    return 0;
}