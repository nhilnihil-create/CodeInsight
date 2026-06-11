#include <bits/stdc++.h>

using namespace std;

int main()
{
    int dh[4] = {1,0,-1,0};
    int dw[4] = {0,1,0,-1};
    int H,W;
    cin >> H >> W;
    vector<vector<char>>c(H,vector<char>(W,' '));
    int bcount = 0;
    for(int i = 0; i < H; i++)
    {
        for(int j = 0; j < W; j++)
        {
            cin >> c[i][j];
            if(c[i][j] == '#') bcount++;
        }
    }
    vector<vector<int>>dist(H,vector<int>(W,-1));
    dist[0][0] = 0;
    queue<pair<int,int>>que;
    que.push(pair(0,0));
    while(!que.empty())
    {
        pair<int,int>p = que.front();
        que.pop();
        for(int i = 0; i < 4; i++)
        {
            pair<int,int>np = pair(p.first + dh[i], p.second + dw[i]);
            if((np.first >= H)||(np.first < 0)||(np.second >= W)||(np.second < 0)) continue;
            if(dist[np.first][np.second] != -1) continue;
            if(c[np.first][np.second] == '#') continue;
            dist[np.first][np.second] = dist[p.first][p.second] + 1;
            que.push(np);
        }
    }
    if(dist[H-1][W-1] == -1) 
    {
        cout << -1 << endl;
        return 0;
    }
    cout << H*W - (dist[H-1][W-1] + 1) - bcount << endl;
    return 0;
}