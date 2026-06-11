#include <bits/stdc++.h>
using namespace std;
int a[] = {-1, 0, 1, 0};
int b[] = {0, 1, 0, -1};
int n, m;
int check(int x, int y){
    if (x>=0 && x<n && y>=0 && y<m)return 1;
    return 0;
}
int main(){
    // int n, m;
    cin>>n>>m;
    vector<string> v(n);
    for (int i=0; i<n; i++)cin>>v[i];
    int visited[n][m]; memset(visited, 0, sizeof(visited));
    int d[n][m]; memset(d, 0, sizeof(d));
    queue<pair<int, int> > q;
    for (int i=0; i<n; i++)for (int j=0; j<m; j++){
        if (v[i][j] == '#'){
            q.push({i, j});
            visited[i][j] = 1;
        }
    }
    while(!q.empty()){
        pair<int, int> z = q.front(); q.pop();
        int x = z.first, y = z.second;
        for (int i=0; i<4; i++){
            if (check(x+a[i], y+b[i]) && visited[x+a[i]][y+b[i]]==0){
                d[x+a[i]][y+b[i]] = d[x][y] + 1;
                visited[x+a[i]][y+b[i]] = 1;
                q.push({x+a[i], y+b[i]});
            }
        }
    }
    int mx = 0;
    for (int i=0; i<n; i++)for (int j=0; j<m; j++)mx = max(mx, d[i][j]);
    cout<<mx<<endl;
}