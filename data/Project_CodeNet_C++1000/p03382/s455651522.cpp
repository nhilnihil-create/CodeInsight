#include<iostream>
#include<algorithm>
#include<cstring>
#include<fstream>
#include<set>
#include<queue>
#include<map>
#include<vector>
using namespace std;
#define N 200005
#define INF 1e9+7
int n,x,a[N],maxi=-1,mini=INF,ans;
int Abs(int p)
{
	return p>0?p:-p;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		a[i]=2*x;
		maxi=max(x,maxi);
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]==(2*maxi))continue;
		if(Abs(maxi-a[i])<mini)
		{
			mini=Abs(maxi-a[i]);
			ans=a[i]/2;
		}
	}
	printf("%d %d",maxi,ans);
	return 0;
}