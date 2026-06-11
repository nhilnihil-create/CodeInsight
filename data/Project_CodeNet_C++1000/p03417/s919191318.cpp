#include<cstdio>
#include<string>
#include<cstring>
#include<utility>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<algorithm>
#include<vector>
#include<iostream>
#define ll long long
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define inf 0x7fffffff
using namespace std;
int main()
{
	int i,j,k,n,m,x,y;
	scanf("%d%d",&x,&y);
	if(x==1&&y==1)
	{
		printf("%d",1);
	}
	else if(x==1)
	{
		printf("%d",y-2);
	}
	else if(y==1)
	{
		printf("%d",x-2);
	}
	else
	{
		printf("%lld",1ll*(x-2)*(y-2));
	}
	return 0;
}
