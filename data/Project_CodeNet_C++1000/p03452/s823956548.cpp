#include<bits/stdc++.h>
#define MAX 100001
using namespace std;
struct Struct
{
	int Left;
	int Right;
	int Dist;
};
int Total,Have;
Struct Array[2*MAX];
int Fa[MAX];
int Dis[MAX];
inline int Find(int X)
{
	if(X!=Fa[X])
	{
		register int Fax;
		Fax=Fa[X];
		Fa[X]=Find(Fa[X]);
		Dis[X]+=Dis[Fax];
	}
	return Fa[X];
}
int main(void)
{
	register int i;
	cin>>Total>>Have;
	for(i=1;i<=Have;i++)
	{
		cin>>Array[i].Left>>Array[i].Right>>Array[i].Dist;
	}
	for(i=1;i<=Total;i++)
	{
		Fa[i]=i;
	}
	for(i=1;i<=Have;i++)
	{
		register int Fl,Fr;
		Fl=Find(Array[i].Left);
		Fr=Find(Array[i].Right);
		if(Fl==Fr&&Dis[Array[i].Left]-Dis[Array[i].Right]!=Array[i].Dist)
		{
			cout<<"No"<<endl;
			return 0;
		}
		if(Fl!=Fr)
		{
			Fa[Fl]=Fr;
			Dis[Fl]=Array[i].Dist+Dis[Array[i].Right]-Dis[Array[i].Left];
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}
