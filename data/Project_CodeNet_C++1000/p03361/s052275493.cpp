#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> s(H);
    for (int i = 0; i < H; i++) cin >> s[i];
    bool exist = true;

    for (int i = 0; i < H; i++) {
       for (int j = 0; j < W; j++) {
            bool canpaint = false;
            if (s[i][j] == '.') continue;
            if (i > 0) if (s[i - 1][j] == '#') canpaint = true;
            if (j > 0) if (s[i][j - 1] == '#') canpaint = true;
            if (i < H - 1) if (s[i + 1][j] == '#') canpaint = true;
            if (j < W - 1) if (s[i][j + 1] == '#') canpaint = true;
            if (!canpaint) {
                //cout << "i " << i << " j " << j << endl;
                exist = false;
                break;
            }
        }
        if (!exist) break;
    }

    if (exist) cout << "Yes" << endl;
    else cout << "No" << endl;
}