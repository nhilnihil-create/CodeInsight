#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;

int H, W;
vector<string> s;
vector<vector<int>> dist;
vector<int> di={0,1,0,-1};
vector<int> dj={1,0,-1,0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> H >> W;
    s.resize(H);
    for (int i=0;i<H;i++) cin >> s[i];
    int white = 0;
    for (int i=0;i<H;i++){
        for (int j=0;j<W;j++){
            if (s[i][j] == '.') white++;
        }
    }
    if (s[0][0] == '#' || s[H-1][W-1] == '#'){
        cout << -1 << "\n";
        return 0;
    }
    dist.resize(H,vector<int>(W,-1));
    queue<pair<pair<int,int>,int>> q;
    dist[0][0] = 0;
    q.push(make_pair(make_pair(0,0),dist[0][0]));
    while (!q.empty()){
        pair<pair<int,int>,int> p = q.front();q.pop();
        for (int x=0;x<4;x++){
            int ni = p.first.first + di[x];
            int nj = p.first.second + dj[x];
            if (ni<0||ni>=H) continue;
            if (nj<0||nj>=W) continue;
            if (s[ni][nj]=='#') continue;
            if (dist[ni][nj] != -1) continue;
            dist[ni][nj] = p.second + 1;
            q.push(make_pair(make_pair(ni,nj),dist[ni][nj]));
        }
    }
    if (dist[H-1][W-1]==-1) {
        cout << -1 << "\n";
        return 0;
    }
    int res = dist[H-1][W-1] + 1;
    int ans = white - res;
    cout << ans << "\n";
}