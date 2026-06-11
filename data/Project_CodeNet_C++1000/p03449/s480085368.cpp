#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
queue<int>qx,qy,qxi;
const int MAXN=105;
bool vis[5][MAXN]; 
int a[5][MAXN],n;
int xx[2]={1,0};
int yy[2]={0,1},ans;
int main()
{
	cin>>n;
	for(int i=1 ; i<=2 ; i++)
	{
		for(int j=1 ; j<=n ; j++)
		{
			cin>>a[i][j];
		}
	}
	qx.push(1);
	qy.push(1);
	qxi.push(a[1][1]);
	while(!qx.empty())
	{
		for(int i=0 ; i<2 ; i++)
		{
			int dx=qx.front()+xx[i];
			int dy=qy.front()+yy[i];
			if(dx>=1&&dx<=2&&dy>=1&&dy<=n)
			{
				qx.push(dx);
				qy.push(dy);
				qxi.push(a[dx][dy]+qxi.front());
			}
		}
		qx.pop();
		qy.pop();
		qxi.pop();
		ans=max(ans,qxi.front());
	}
	cout<<ans<<endl;
	return 0;
}