#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    char s[50][50];
    cin >> h >> w;
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            cin >> s[i][j];
        }
    }
    //上下左右を調べるための配列を用意する
    const int dx[4] = {0, 0, 1,-1};
    const int dy[4] = {1,-1, 0, 0};
    //can1が最後までtrueのままならYesを出力する
    bool can1 = true;
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (s[i][j] == '.') continue;
            /*'#'が出たら上下左右に'#'があるかどうかを調べる。
            なかったらループから出る*/
            bool can2 = false;
            for (int d=0; d<4; d++) {
                int ni = i + dy[d];
                int nj = j + dx[d];
                //以下二文で枠外を探索してしまう場合を除外する
                if (ni < 0 || ni >= h) continue;
                if (nj < 0 || nj >= w) continue;
                //'#'があったらcan2をtrueにして続行。can2がfalseのままならループから出る。
                if (s[ni][nj] == '#') can2 = true;
            }
            if (!can2) {
                can1 = false;
                break;
            }
        }
        if (!can1) break;
    }
    
    if (can1) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}