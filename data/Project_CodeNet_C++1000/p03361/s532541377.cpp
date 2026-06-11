#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    int H, W;
    cin >> H >> W;
    vector<string>masu(H);
    for (int i=0; i<H; i++) {
        cin >> masu.at(i);
    }

    int x[4] = {0, 0, 1, -1};
    int y[4] = {1, -1, 0, 0};
    bool can_go = true;
    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            if (masu[i][j] == '.') continue;
            bool can_idou = false;
            for (int k=0; k<4; k++) {
                int new_y = i + y[k];
                int new_x = j + x[k];
                if (new_y >= H || new_y < 0) continue;
                if (new_x >= W || new_x < 0) continue;
                if (masu[new_y][new_x] == '#') can_idou = true;
            }

            if (!can_idou) {
                can_go = false;
                break;
            }
        }
    }

    if (can_go) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}