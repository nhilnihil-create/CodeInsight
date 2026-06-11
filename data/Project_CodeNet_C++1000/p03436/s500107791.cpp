#include<bits/stdc++.h>
using namespace std;
const int N=50+5;
struct node{
	int x,y;
	node(int x=0,int y=0){
		this->x=x;
		this->y=y;
	}
};
queue<node> qe;
int n,m,sum;
char G[N][N];
bool vis[N][N];
int det[N][N];
int xx[]={0,0,-1,1};
int yy[]={1,-1,0,0};
int main(){
	scanf("%d %d",&n,&m);
	clock_t s=clock();
	for(int i=1;i<=n;++i){
		scanf("%s",G[i]+1);
		//for(int j=1;j<=m;++j) G[i][j]='.';
		for(int j=1;j<=m;++j)
			if(G[i][j]=='.') sum++;
	}
	if(G[1][1]=='#' || G[n][m]=='#'){
		puts("-1");return 0;
	}
	qe.push(node(1,1));
	while(!qe.empty()){
		node u=qe.front();qe.pop();
		//cout<<u.x<<" "<<u.y<<" "<<qe.size()<<"\n";
		vis[u.x][u.y]=true;
		for(int i=0;i<4;++i){
			int x=u.x+xx[i],y=u.y+yy[i];
			if(x<1 || x>n || y<1 || y>m) continue;
			if(vis[x][y] || G[x][y]=='#') continue;
			det[x][y]=det[u.x][u.y]+1;
			qe.push(node(x,y));vis[x][y]=true;
		}
	}
	if(vis[n][m]==0){
		puts("-1");return 0;
	}
//	cout<<sum<<" "<<det[n][m]+1<<"\n";
	printf("%d\n",sum-det[n][m]-1);
}