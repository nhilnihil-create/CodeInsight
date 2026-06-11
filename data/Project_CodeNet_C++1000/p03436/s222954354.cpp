#include <bits/stdc++.h>
using namespace std;

const int N=2e5+100;
const int mod=1e9+7;
typedef long long ll;

int a[N];
typedef pair<int,int> pa;
int dv[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
char path[100][100];
int n,m;
int vis[100][100];
void bfs(int x,int y)
{
    queue<pa>q;
    q.push({x,y});
    vis[x][y]=1;
    while(q.size()){
        pa k=q.front();q.pop();
        for(int i=0;i<4;i++) {
             int xx=k.first+dv[i][0];
             int yy=k.second+dv[i][1];
             if(path[xx][yy]=='.' && xx>=1 && xx<=n && yy>=1 && yy<=m && !vis[xx][yy]){
                  q.push({xx,yy});
                  vis[xx][yy]=vis[k.first][k.second]+1;
             }
        }
    }

}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    int ans=0;
    for(int i=1;i<=n;i++) {
        cin>>path[i]+1;
        for(int j=1;j<=m;j++) {
            if(path[i][j]=='.')
                ans++;
        }
    }
    bfs(1,1);
    if(!vis[n][m])  cout<<-1<<endl;
    else {
        cout<<ans-vis[n][m]<<endl;
    }
    return 0;
}
