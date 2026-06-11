#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
using ll = long long;
using pii = pair<int, int>;


int main(void)
{
    int H, W;
    cin >> H >> W;

    vector<string> s(H);
    int black = 0;
    for (int i = 0; i < H; i++)
    {
        cin >> s[i];
        for (int j = 0; j < W; j++)
        {
            if(s[i][j] == '#'){
                black++;
            }
        }
    }

    vector<vector<int>> dist(H, vector<int>(W, INF));
    vector<pii> dirs = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    queue<pii> que;
    pii start = {0,0};
    que.push(start);
    dist[start.first][start.second] = 1;

    while (!que.empty())
    {
        pii current = que.front();
        que.pop();

        for (int d = 0; d < 4; d++)
        {
            int nextH = current.first + dirs[d].first;
            int nextW = current.second + dirs[d].second;

            if(nextH < 0 || nextH >= H) continue;
            if(nextW < 0 || nextW >= W) continue;

            if(s[nextH][nextW] != '.') continue;

            if(dist[nextH][nextW] > dist[current.first][current.second] + 1){
                
                dist[nextH][nextW] = dist[current.first][current.second] + 1;
                
                que.push({nextH, nextW});
            }
        }
    }
    
    int used = dist[H-1][W-1];

    if(used >= INF){
        cout << -1 << endl;
        return 0;
    }

    int unused = H * W - used;
    int ans = unused - black;

    cout << ans << endl;

    return 0;
}
