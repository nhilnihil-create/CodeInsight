#include<iostream>
using namespace std;

int main() {
    int H, W; cin >> H >> W;
    string S[H];
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int ans = 0;
            if (i != 0) { // upper
                if (S[i - 1][j] == '#') {
                    ans++;
                }
            }
            if (i != 0 && j != W) { // upper right
                if (S[i - 1][j + 1] == '#') {
                    ans++;
                }
            }
            if (i != 0 && j != 0) { // upper left
                if (S[i - 1][j - 1] == '#') {
                    ans++;
                }
            }
            if (j != W) { // right
                if (S[i][j + 1] == '#') {
                    ans++;
                }
            }
            if (j != 0) { // left
                if (S[i][j - 1] == '#') {
                    ans++;
                }
            }
            if (i != H) { // lower
                if (S[i + 1][j] == '#') {
                    ans++;
                }
            }
            if (j != W && i != H) { // lower right
                if (S[i + 1][j + 1] == '#') {
                    ans++;
                }
            }
            if (i != H && j != 0) { // lower left
                if (S[i + 1][j - 1] == '#') {
                    ans++;
                }
            }
            if (S[i][j] != '#') {
                S[i][j] = ans + '0';
            }
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << S[i][j];
        }
        cout << endl;
    }
}
