#include <bits/stdc++.h>
using namespace std;

/*
    すべての＃が、隣接マスに＃をもつならばYes。そうでなければNo
*/

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<char>> M(H, vector<char>(W));
    int dx[4] = {1, 0,  0, -1};
    int dy[4] = {0, 1, -1,  0};

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> M[i][j];
        }
    }

    bool result = true;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (M[i][j] == '#') {
                int c_n = 0;
                for (int d = 0; d < 4; d++)
                {
                    int cx = i + dx[d];
                    int cy = j + dy[d];
                    if (cx < 0 || H<= cx)
                        continue;
                    if (cy < 0 || W <= cy)
                        continue;
                    
                    if (M[cx][cy] == '#')
                        c_n++;
                }
                if (c_n == 0) {
                    result = false;
                    break;
                }
            }
        }
        
    }

    if (result) {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}