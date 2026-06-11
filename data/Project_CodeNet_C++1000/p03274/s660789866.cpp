#include<bits/stdc++.h>

using namespace std;

const int N=100000+10;
const int inf=0x3f3f3f3f;

int n,k;
int dis[N];

int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;++i)
	{
		cin>>dis[i];
	}
	int ret=inf;
	for(int i=1;i+k-1<=n;++i)
	{
		int x,y;
		x=min(abs(dis[i]),abs(dis[i+k-1]));
		y=dis[i+k-1]-dis[i];
		ret=min(ret,x+y);
		//cout<<x<<" "<<y<<" ";
		//cout<<abs(dis[i])<<" "<<abs(dis[i+k-1])<<endl;;
	}
	cout<<ret<<endl;
	//for(int i=1;i<=n;++i)cout<<dis[i];
	return 0;
}