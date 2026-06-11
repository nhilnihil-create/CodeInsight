#include<bits/stdc++.h>
using namespace std;

const int maxl=1<<18;

int n,up;
int mx[maxl],sec[maxl];
int f[maxl];

inline void upd(int i,int x)
{
	if(x>mx[i])
		sec[i]=mx[i],mx[i]=x;
	else if(x>sec[i])
		sec[i]=x;
}

inline void prework()
{
	scanf("%d",&n);up=1<<n;
	for(int i=0;i<up;i++)
		scanf("%d",&mx[i]);
	for(int j=0;j<n;j++)
		for(int i=0;i<up;i++)
		if((i>>j)&1)
		{
			if(mx[i^(1<<j)])
				upd(i,mx[i^(1<<j)]);
			if(sec[i^(1<<j)])
				upd(i,sec[i^(1<<j)]);
		}
}

inline void mainwork()
{
	for(int i=1;i<up;i++)
	{	
		f[i]=max(f[i-1],mx[i]+sec[i]);
		printf("%d\n",f[i]);
	}
}

int main()
{
	prework();
	mainwork();
	return 0;
}