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
    vector<string> masu(H);
    vector<string> okikae(H);
    for (int i=0; i<H; i++) {
        cin >> masu.at(i);
        okikae[i] = masu[i];
    }

    int x[8] = {-1, 1, 0, 0, 1, 1, -1, -1};
    int y[8] = {0, 0, -1, 1, 1, -1, -1, 1};

    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            if (masu[i][j] == '#') continue;
            int count = 0;
            for (int k=0; k<8; k++) {
                int new_x = j + x[k];
                int new_y = i + y[k];
                if (new_x < 0 || new_x >= W) continue;
                if (new_y < 0 || new_y >= H) continue;
                if (masu[new_y][new_x] == '#') count += 1;
            }

            okikae[i][j] = to_string(count)[0];
        }
    }

    for (int i=0; i<H; i++) {
        cout << okikae[i] << endl;
    }
    return 0;
}