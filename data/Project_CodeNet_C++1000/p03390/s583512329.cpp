#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	int x,y,T,ans,tmp,tmp2;
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		scanf("%d%d",&x,&y);
		if(x>y)
		{
			swap(x,y);
		}
		if(y==1)
			ans=0;
		else
		{
			ans+=x-1;
			tmp=sqrt((long long)y*x);
			//printf("%d\n",tmp);
			if((long long)tmp*tmp==(long long)x*y)
			{
			//	printf("*");
				ans--;
			}
			ans+=tmp;
			tmp2=((long long)x*y-1)/tmp;
			if(tmp2-x>0)
				ans+=(tmp2-x);
			if(((long long)x*y-1)/tmp2==tmp)
				ans--;
	//		if(x+1==y)
	//			ans--;
	//		if((long long)tmp*(tmp+1)>=(long long)x*y)
	//			ans--;
		}
		printf("%d\n",ans);
	}
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	
	return 0;
}
