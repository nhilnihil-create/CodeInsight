#include <bits/stdc++.h>

using namespace std;

int main()
{
    int H,W;
    int dh[4] = {1,0,-1,0};
    int dw[4] = {0,1,0,-1};
    cin >> H >> W;
    vector<vector<char>>c(H,vector<char>(W,' '));
    vector<vector<int>>dist(H,vector<int>(W,-1));
    queue<pair<int,int>>que;
    for(int i = 0; i < H; i++)
    {
        for(int j = 0; j < W; j++)
        {
            cin >> c[i][j];
            if(c[i][j] == '#') dist[i][j] = 0,que.push(pair(i,j));
        }
    }
    int ans = 0;
    while(!que.empty())
    {
        pair<int,int>p = que.front();
        que.pop();
        for(int i = 0; i < 4; i++)
        {
            pair<int,int> np = pair(p.first + dh[i], p.second + dw[i]);
            if((np.first < 0)||(np.first >= H)||(np.second < 0)||(np.second >= W)) continue;
            if(dist[np.first][np.second] != -1) continue;
            dist[np.first][np.second] = dist[p.first][p.second] + 1;
            ans = max(ans,dist[np.first][np.second]);
            que.push(np);
        }
    }
    cout << ans << endl;
}