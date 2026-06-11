#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int H, W;
    cin >> H >> W;

    vector<vector<int>> s(H, vector<int>(W));
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            char c;
            cin >> c;
            if (c == '#')
                s[i][j] = 1;
            else
                s[i][j] = 0;
        }
    }

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    int isolated = 0;
    
    for (int h = 0; h < H; h++)
    {
        for (int w = 0; w < W; w++)
        {
            if(s[h][w] == 1){
                int neighbor = 0;
                for(int i = 0; i < 4; i++){
                    int hi = h + dy[i];
                    int wi = w + dx[i];

                    if(hi <0 || hi >= H || wi < 0 || wi >= W) continue;
                    
                    if(s[hi][wi] == 1) neighbor++;
                }

                if(neighbor == 0) isolated++;
            }
        }
    }

    if(isolated == 0){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}
