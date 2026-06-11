#include <bits/stdc++.h>
#define INF 1e8

using namespace std;
typedef long long int ll;


int main()
{
    int H,W; cin >> H >> W;
    vector<vector<char>>G(H,vector<char>(W));
    int white = 0;
    int black = 0;
    for(int i = 0; i < H; i++)
    {
        for(int j = 0; j < W; j++)
        {
            cin >> G[i][j];
            if(G[i][j] == '.') white++;
            else black++;
        }
    }
    queue<pair<int,int>>que;
    que.push(pair(0,0));
    vector<vector<int>>dist(H,vector<int>(W,-1));
    dist[0][0] = 0;
    int dh[4] = {1,0,-1,0};
    int dw[4] = {0,1,0,-1};
    while(!que.empty())
    {
        auto p = que.front();
        int h = p.first;
        int w = p.second;
        que.pop();
        for(int i = 0; i < 4; i++)
        {
            int nh = h + dh[i];
            int nw = w + dw[i];
            if(nh < 0 || nw < 0 || nh >= H || nw >= W) continue;
            if(dist[nh][nw] != -1) continue;
            if(G[nh][nw] == '#') continue;
            dist[nh][nw] = dist[h][w] + 1;
            que.push(pair(nh,nw));
        }
    }
    if(dist[H-1][W-1] == -1)
    {
        cout << -1 << endl;
        return 0;
    }
    int ans = H*W - (dist[H-1][W-1]+1) - black;
    cout << ans << endl;
    return 0;
}