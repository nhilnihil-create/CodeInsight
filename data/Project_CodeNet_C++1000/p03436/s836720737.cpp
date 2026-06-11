#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,z,ans=0,sum=0,flag=1;
struct node{
	int x,y,step;
};
char c[55][55];
bool vis[55][55];
int s1[5]={0,1,-1,0,0};
int s2[5]={0,0,0,1,-1};
queue<node> q;




void bfs()
{
	int i,j;
	node s;
	s.x=s.y=1;
	
	
	
	s.step=0;
	
	
	
	
	q.push(s);
	vis[1][1]=1;
	while(!q.empty())
	{
		
		node u=q.front();
		
		
		
		
		if(u.x==n&&u.y==m)
		{
			flag=0;
			ans=u.step;
			break;
		}
		
		
		
		
		q.pop();
		for(i=1;i<=4;i++)
		{
			int xx,yy;
			xx=u.x+s1[i];
			yy=u.y+s2[i];
			if(xx<1||xx>n||yy<1||yy>m) continue;
			if(vis[xx][yy]||c[xx][yy]=='#') continue;
			node v;
			v.x=xx;
			v.y=yy;
			v.step=u.step+1;
			q.push(v);
			vis[xx][yy]=1;
		}
	}
}
int main()
{
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	{
		cin>>c[i][j];
		if(c[i][j]=='.') sum++;
	}
	
	
	bfs();
	
	
	if(flag) cout<<-1;
	else cout<<sum-(ans+1);
	return 0;
}	