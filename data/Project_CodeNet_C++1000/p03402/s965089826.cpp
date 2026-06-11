#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef long long ll;

int main() {
    int A, B;
    cin >> A >> B;

    vector<vector<int>> black(50, vector<int>(100, 0)); // 100 x 50 の黒マス
    vector<vector<int>> white(50, vector<int>(100, 1)); // 100 x 50 の白マス

    A--;
    B--;

    int x = 1;
    int y = 1;
    rep(i, A) {
        black[y][x] = 1;
        x += 2;
        if (x > 98) {
            x = 1;
            y += 2;
        }
    }

    x = 1;
    y = 1;
    rep(i, B) {
        white[y][x] = 0;
        x += 2;
        if (x > 98) {
            x = 1;
            y += 2;
        }
    }

    cout << 100 << " " << 100 << endl;
    rep(i, 2) {
        vector<vector<int>> board = black;
        if (i == 1) board = white;

        rep(h, 50) {
            rep(w, 100) {
                if (board[h][w] == 0) cout << "#";
                else cout << ".";
            }
            cout << endl;
        }
    }
}
