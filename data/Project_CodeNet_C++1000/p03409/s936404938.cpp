#include<iostream>
#include<string.h>
using namespace std;
const int N=110;
int match[N];
bool vis[N],flag[N][N];
struct node {
	int x,y;
}r[N],b[N];//红色和蓝色的点 
int n;
bool find(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(!vis[i]&&flag[x][i])
		{
			vis[i]=1;
			if(match[i]==0||find(match[i]))
			{
				match[i]=x;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>r[i].x>>r[i].y;
	for(int i=1;i<=n;i++) cin>>b[i].x>>b[i].y;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(r[i].x<b[j].x&&r[i].y<b[j].y)
			{
				flag[i][j]=1;//两者可以配对 
			}
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++)
	{   
                memset(vis,0,sizeof(vis));
		if(find(i))//最大匹配 
		{
			ans++;
		}
	 } 
	cout<<ans<<endl;
}