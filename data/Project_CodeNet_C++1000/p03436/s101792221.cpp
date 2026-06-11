#include <bits/stdc++.h>

using namespace std;

int dw[4] = {1,0,-1,0};
int dh[4] = {0,1,0,-1};

int main()
{
    int H,W;
    cin >> H >> W;
    vector<vector<char>>G(H,vector<char>(W,'.'));
    int num = 0;
    for(int i = 0; i < H; i++) 
    {
        for(int j = 0; j < W; j++)
        {
            cin >> G[i][j];
            if(G[i][j] == '.') num++;
        }
    }
    vector<vector<int>>dist(H,vector<int>(W,-1));
    queue<pair<int,int>>que;
    que.push(pair(0,0));
    dist[0][0] = 1;
    while(!que.empty())
    {
        int h = que.front().first;
        int w = que.front().second;
        que.pop();
        for(int i = 0; i < 4; i++)
        {
            int nh = h + dh[i];
            int nw = w + dw[i];
            if(nh >= H || nw >= W || nh < 0 || nw < 0) continue;
            if(dist[nh][nw] != -1) continue;
            if(G[nh][nw] == '#') continue;
            dist[nh][nw] = dist[h][w] + 1;
            que.push(pair(nh,nw));
        }
    }
    if(dist[H-1][W-1] == -1) cout << -1 << endl;
    else cout << num - dist[H-1][W-1] << endl;
}