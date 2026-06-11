#include <bits/stdc++.h>

#include <vector>

using namespace std;
using ll = long long;

int dh[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dw[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> S(H + 2);
    for (int i = 1; i <= H; i++) {
        string tmp;
        cin >> tmp;
        tmp = "." + tmp + ".";
        S[i] = tmp;
    }

    for (int i = 0; i < W + 2; i++) {
        S[0] += ".";
        S[H + 1] += ".";
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i + 1][j + 1] == '#') {
                cout << "#";
                continue;
            }
            int c = 0;
            for (int k = 0; k < 8; k++) {
                if (S[i + 1 + dh[k]][j + 1 + dw[k]] == '#') c++;
            }
            cout << c;
        }
        cout << endl;
    }

    return 0;
}
