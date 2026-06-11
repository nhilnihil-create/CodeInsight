#include<bits/stdc++.h>
using namespace std;

int main()
{
    int H, W; cin >> H >> W;
    vector<vector<char>> grid(H, vector<char> (W));
    for(int i = 0 ; i < H ; i++)
    for(int j = 0 ; j < W ; j++)
        cin >> grid[i][j];
    
    vector<vector<int>> path(H, vector<int>(W,0));
    for(int i = 0 ; i < H ; i++){
        if(grid[i][0] != '#')
        path[i][0] = 1;
        else break;
    }
    for(int i = 0 ; i < W ; i++){
        if(grid[0][i] != '#')
        path[0][i] = 1;
        else break;
    }

    for(int i = 1 ; i < H ; i++)
    {
        for(int j = 1 ; j < W ; j++)
        {
            if(grid[i][j] != '#')
            path[i][j] = (path[i][j-1] + path[i-1][j]) % (1000000007);
            else
            path[i][j] = 0;
        }
    }

    cout << path[H-1][W-1] % 1000000007;
}
