#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
int n,a[200020];
bool check(int w)
{
	map<int,int>s;
	int len=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i]>a[i-1])len=a[i];
		else
		{
			while(s.size()&&s.rbegin()->first>a[i])s.erase(s.rbegin()->first);
			len=a[i];++s[len];
			int x=len;
			while(s[x]==w)
			{
				if(x==1)return 0;
				s[x]-=w;
				++s[x-1];
				--x;
			}
		}
	}
	return 1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	bool flag=0;
	for(int i=1;i<n;++i)if(a[i]>=a[i+1])flag=1;
	if(!flag)return printf("1"),0;
	int l=2,r=n,mid;
	while(l<r)
	{
		mid=l+r>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	printf("%d",l);
	return 0;
}
