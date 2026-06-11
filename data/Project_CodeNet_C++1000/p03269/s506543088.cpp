#include<bits/stdc++.h>
using namespace std;
const int Log=19;
int L,m;
int p2[Log+5];
vector<int> oa,ob,ow;
void add(int u,int v,int w)
{
	oa.push_back(u);
	ob.push_back(v);
	ow.push_back(w);
	m++;
	return;
}
int main()
{
	p2[0]=1;
	for(int i=1;i<=Log;i++) p2[i]=p2[i-1]*2;
	scanf("%d",&L);
	for(int i=1;i<=18;i++)
	{
		add(i,i+1,p2[i-1]);
		add(i,i+1,0);
	}
	int bac=0;
	for(int i=Log;i>=0;i--)
	{
		if(!(p2[i]&L)) continue;
		if(i==19)
		{
			add(19,20,p2[18]);
			add(19,20,0);
		}
		else add(i+1,20,bac);
		bac|=p2[i];
	}
	printf("20 %d\n",m);
	for(int i=0;i<(int)oa.size();i++) printf("%d %d %d\n",oa[i],ob[i],ow[i]);
	return 0;
}