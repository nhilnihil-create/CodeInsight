#include <bits/stdc++.h>
#define INF 1e8

using namespace std;
typedef long long int ll;


int main()
{
    int H,W; cin >> H >> W;
    vector<vector<char>>G(H,vector<char>(W));
    vector<vector<int>>d(H,vector<int>(W,-1));
    queue<pair<int,int>>que;
    for(int i = 0; i < H; i++)
    {
        for(int j = 0; j < W; j++)
        {
            cin >> G[i][j];
            if(G[i][j] == '#') 
            {
                d[i][j] = 0;
                que.push(pair(i,j));
            }
        }
    }
    int dh[4] = {1,0,-1,0};
    int dw[4] = {0,1,0,-1};
    while(!que.empty())
    {
        auto p = que.front();
        que.pop();
        int h = p.first;
        int w = p.second;
        for(int i = 0; i < 4; i++)
        {
            int nh = h + dh[i];
            int nw = w + dw[i];
            if(nh >= H || nh < 0 || nw < 0 || nw >= W) continue;
            if(d[nh][nw] != -1) continue;
            d[nh][nw] = d[h][w] + 1;
            que.push(pair(nh,nw));
        }
    }
    int ans = 0;
    for(int i = 0; i < H; i++) for(int j = 0; j < W; j++) ans = max(ans,d[i][j]);
    cout << ans << endl;
}