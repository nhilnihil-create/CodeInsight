#include<bits/stdc++.h>
using namespace std;

#define INF 1e5 

int prise[100006],f[100006];
bool isprise[100006];

void os(int r)
{
	int tot=0;
	memset(isprise,1,sizeof(isprise));
	isprise[1]=isprise[0]=0;
	for(int i=2;i<=r;i++)
	{
		if(isprise[i])
			prise[tot++]=i;
		for(int j=0;i*prise[j]<=r;j++)
		{
			isprise[i*prise[j]]=0;
			if(i%prise[j]==0)
				break;
		}
	}
}

void Prefix_and()
{
	for(int i=2;i<=100005;i++)
	{
		f[i]=f[i-1];
		if(i%2==1&&isprise[i]&&isprise[(i+1)/2])
			f[i]++;
	}
}

int main()
{
	int n,x,y;
	os(100005);
	Prefix_and();
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		cout<<f[y]-f[x-1]<<endl;
	}
	return 0;
}