#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,q,lt,rt,mid,i,w1,w2;
char s[200005],ch1[200005][2],ch2[200005][2];
bool workl(int x)
{
	for(int i=1;i<=q;++i)
		if(s[x]==ch1[i][0])
		{
			if(ch2[i][0]=='L')
				--x;
			else
				++x;
			if(x<1)
				return true;
			if(x>n)
				return false;
		}
	return false;
}
bool workr(int x)
{
	for(int i=1;i<=q;++i)
		if(s[x]==ch1[i][0])
		{
			if(ch2[i][0]=='L')
				--x;
			else
				++x;
			if(x<1)
				return false;
			if(x>n)
				return true;
		}
	return false;
}
int main()
{
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	for(i=1;i<=q;++i)
		scanf("%s%s",ch1[i],ch2[i]);
	if(!workl(1))
		w1=0;
	else
	{
		lt=1,rt=n;
		while(lt<rt)
		{
			mid=lt+rt+1>>1;
			if(workl(mid))
				lt=mid;
			else
				rt=mid-1;
		}
		w1=lt;
	}
	if(!workr(n))
		w2=0;
	else
	{
		lt=1,rt=n;
		while(lt<rt)
		{
			mid=lt+rt>>1;
			if(workr(mid))
				rt=mid;
			else
				lt=mid+1;
		}
		w2=n-lt+1;
	}
	printf("%d",n-min(n,w1+w2));
	return 0;
}
