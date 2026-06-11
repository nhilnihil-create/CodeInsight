#include<bits/stdc++.h>
using namespace std;
char s[1005][1005];
int d[1005][1005];
int x[1000005],y[1000005];
int h,w;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int main(){
	scanf("%d%d",&h,&w);
	getchar();
	int t=0;
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			scanf("%c",&s[i][j]);
			if(s[i][j]=='.')
				d[i][j]=1e9;
			else{
				d[i][j]=0;
				x[t]=i;
				y[t++]=j;
			}
		}
		getchar();
	}
	int s=0,ans=0;
	while(s<t){
		int xx=x[s],yy=y[s++];
		for(int i=0;i<4;i++){
			int u=xx+dx[i];
			int v=yy+dy[i];
			if(u<1||u>h||v<1||v>w||d[u][v]<=d[xx][yy]+1)
				continue;
			d[u][v]=d[xx][yy]+1;
			ans=max(ans,d[u][v]);
			x[t]=u;
			y[t++]=v;
		}
	}
	printf("%d\n",ans);
}