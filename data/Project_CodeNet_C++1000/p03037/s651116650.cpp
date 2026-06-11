#include <iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
#include<math.h>
#define ll long long
using namespace std;
int main()
{
	int n,m,l,r,i;
	int f[100010],minn=99999999,maxx=-99999999;
	cin>>n>>m;
	memset(f,0,sizeof(f));
	int mm=m;
	while(mm--)
	{
		cin>>l>>r;
		for(i=l;i<=r;i++)
		{
			f[i]++;
		}
		minn=min(minn,l);
		maxx=max(maxx,r);
	}
	int cnd=0;
	for(i=minn;i<=maxx;i++)
	{
		if(f[i]==m)
		cnd++;
	}
	cout<<cnd<<endl;
	return 0;
 } 