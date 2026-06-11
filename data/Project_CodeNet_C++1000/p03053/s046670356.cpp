#include<bits/stdc++.h>
 
using namespace std;
 
const int N = 1e3+5;
 
int n,m,ans;
 
int dx[4]={1,0,-1,0};
 
int dy[4]={0,1,0,-1};
 
char e[N][N];
 
struct node{
 
    int x;
 
    int y;
 
    int step;
 
};
 
queue<node>Q;
 
 
 
void bfs(){
 
    while(!Q.empty()){
 
        node a=Q.front();
 
        Q.pop();
 
        ans=max(ans,a.step);
 
        for(int i=0;i<4;i++)
		{
 
            node b;
 
            int xx=a.x+dx[i];
 
            int yy=a.y+dy[i];
 
            if(xx<0||xx>=n||yy<0||yy>=m)
				continue;
 
            b.x=xx;
 
            b.y=yy;
 
            b.step=a.step+1;
 
            if(e[xx][yy]=='.')
			{
                e[xx][yy]='#';
                Q.push(b);
            }
 
        }
 
    }
}
 
int main()
 
{
 
    std::ios::sync_with_stdio(false);
 	cin.tie(0);
    cin>>n>>m;
 
    for(int i=0;i<n;i++)
	{
        cin>>e[i];
        for(int j=0;j<m;j++)
            if(e[i][j]=='#')
				Q.push(node{i,j,0});
    }
 
    bfs();
 
    cout<<ans<<endl;
 
    return 0;
}
