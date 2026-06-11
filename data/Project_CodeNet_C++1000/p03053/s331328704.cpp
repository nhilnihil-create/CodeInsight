#include<bits/stdc++.h>
using namespace std;

#define Q int t; scanf("%d", &t); for(int q=1; q<=t; q++)
typedef long long int lli;
typedef pair<int, int> pi;


int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> gri(n);
    for(int i=0; i<n; i++){
        cin >> gri[i];
    }
    int xx[] = {1, -1, 0, 0};
    int yy[] = {0, 0, 1, -1};
    queue<pi> qu;
    int dis[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(gri[i][j] == '#'){
                qu.push({i, j});
                dis[i][j] = 0;
            }
        }
    }
    while(!qu.empty()){
        pi u = qu.front();
        qu.pop();
        int x = u.first;
        int y = u.second;
        for(int i=0; i<4; i++){
            int gx = x+xx[i];
            int gy = y+yy[i];
            if(gx<n && gx>=0 && gy>=0 && gy<m && gri[gx][gy] == '.'){
                dis[gx][gy] = dis[x][y]+1;
                gri[gx][gy] = '#';
                qu.push({gx, gy});
            }
        }
    }
    int mx = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            mx = max(mx, dis[i][j]);
        }
    }
    cout << mx << "\n";

    return 0;
}
