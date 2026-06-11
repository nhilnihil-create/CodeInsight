#include<bits/stdc++.h>
using namespace std;
int n;
int d3,d5,d7;
int ans,cnt;
int now;
void DFS(int k,int m)
{
	if(k > m)
	{
		if(d3&&d5&&d7&&now<=n)
		   ++cnt;
		return;
	}
	d3++;
	now*=10;
	now+=3;
	DFS(k+1,m);
	d3--;
	now-=3;
	now/=10;
	d5++;
	now*=10;
	now+=5;
	DFS(k+1,m);
	d5--;
	now-=5;
	now/=10;
	d7++;
	now*=10;
	now+=7;
	DFS(k+1,m);
	d7--;
	now-=7;
	now/=10;
}

int main()
{
	cin>>n;
	int s=n;
	int lens=0;
	while(s)
	{
		s/=10;
		lens++;
	}
	for(int i=3;i<=lens;++i)
	{
		now=cnt=d3=d5=d7=0;
		DFS(1,i);
		ans+=cnt;
	}
	printf("%d\n",ans);
	return 0;
 } 