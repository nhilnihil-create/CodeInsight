#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int vis[1200][1200],dis[1200][1200];
int R,C,f;
int row[]= {1,0,-1,0,1,-1,1,-1};
int colm[]= {0,1,0,-1,1,-1,-1,1};
string paint[500];
void bfs(int input_x,int input_y)
{
    queue<pair<int,int> >q;
    vis[input_x][input_y] = 1;
    dis[input_x][input_y]   = 0;
    q.push(make_pair(input_x,input_y));
    int child=0;
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        child++;
        for(int i=0; i<4; i++)
        {
            int u = x+row[i];
            int v = y+colm[i];
            if(0<=u && u<R && 0<=v && v<C)
            {
                if(vis[u][v]==0 && paint[u][v]=='#')
                {
                    vis[u][v]=1;
                    dis[u][v] = dis[x][y]+1;
                    q.push(make_pair(u,v));
                }
            }
        }
    }
   if(child==1)
    f=1;
}

int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);

    cin>>R>>C;
    for(int i=0;i<R;i++)
        cin>>paint[i];
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(!vis[i][j] && paint[i][j]=='#')
                bfs(i,j);
        }
    }
    if(f)
        cout<<"No"<<endl;
    else
        cout<<"Yes"<<endl;



    return 0;
}
