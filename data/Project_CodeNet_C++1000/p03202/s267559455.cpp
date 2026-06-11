#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int n,a[202020];
map<int,int> num;
bool check(int x)
{
	num.clear();
	for(int i=1;i<=n;i++)
	if(a[i]<=a[i-1])
	{
		while(num.size()&&(*(--num.end())).first>a[i]) num.erase(--num.end());
		int an=a[i];
		while(an>=1&&num.size()&&num[an]==x-1) num.erase(--num.end()),an--;
		if(!an) return 0;
		num[an]++;
	}
	return 1;
}
			
int main()
{
	scanf("%d",&n);
	int fl=0;
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]),fl|=(a[i]<=a[i-1]);
	if(!fl) puts("1");
	else
	{
		int l=2,r=n,mid;
		while(l<r)
		{
			mid=(l+r)/2;
		//	cout<<l<<" "<<r<<" "<<mid<<endl;
			if(check(mid)) r=mid;
			else l=mid+1;
		}
		printf("%d\n",l);
	}
	return 0;
}