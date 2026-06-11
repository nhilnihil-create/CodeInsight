#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    int bom[h][w];
    char c;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> c;
            bom[i][j] = (c == '#' ? -1 : 0);
        }
    }
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (bom[i][j] == -1) {
                for (int k = i-1; k <= i+1; k++) {
                    for (int l = j-1; l <= j+1; l++) {
                        if ((0 <= k && k < h) && (0 <= l && l < w)) {
                            if (bom[k][l] != -1) bom[k][l]++;
                        }
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (bom[i][j] == -1) {
                cout << '#';
            } else {
                cout << bom[i][j];
            }
        }
        cout << endl;
    }

    return 0;
}
