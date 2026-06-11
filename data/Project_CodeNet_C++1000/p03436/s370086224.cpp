#include<bits/stdc++.h>
using namespace std;
bool vis[100][100];
int fx[] = {0,0,1,-1};
int fy[] = {1,-1,0,0};
int dist[100][100];
int main()
{
    int n,m;
    cin >> n >> m ;
    char ara[n+10][m+10];

    int cnt = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> ara[i][j] ;
         //   dist[i][j] = INT_MAX;
            if(ara[i][j]=='#')cnt++;
        }
    }
   // cout << cnt << " " << n*m << endl;

   // memset(dist,2,sizeof dist);


    queue <pair<int,int> > q;
    bool mrk = 0;
    if(ara[0][0]=='.' && ara[n-1][m-1]=='.')
    q.push(make_pair(0,0)),dist[0][0] = 0,vis[0][0]=0;
    else mrk = 1;

    //cout << dist[n-1][m-1] << endl;
    if(!mrk)
    while(!q.empty())
    {
        pair<int,int> prnt = q.front() ;
        q.pop();
        int px = prnt.first;
        int py = prnt.second;
        for(int i=0; i<4; i++)
        {

            int cx = px + fx[i];
            int cy = py + fy[i];

            if(cx>=0 && cx<n && cy>=0 && cy<m && ara[cx][cy]=='.'  && vis[cx][cy]==0)
            {
                vis[cx][cy] = 1;
    //            cout << px << " " << py << endl;
      //          cout << cx << " " << cy << endl;
                dist[cx][cy] = dist[px][py]+1 ;
                q.push(make_pair(cx,cy));
            }
        }

    }

     if(!vis[n-1][m-1])mrk = 1;
    int rasta = 0 ;
     rasta =  dist[n-1][m-1]+1 ;
      if(!mrk)
      cout << n*m - cnt - rasta << endl;
      else cout << "-1" << endl;
}
