#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<set>
#include<complex>
#include<map>
using namespace std;
inline int ri()
{
	register int x=0;
	bool f=0;
	register char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')	f=1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	if(f)	return -x;
	else	return x;
}
void wi(int x)
{
	if(x<0)	putchar('-'),x=-x;
	if(x>9)	wi(x/10);
	putchar(x%10+'0');
}
const int N=1e5+7;
int a[N];
int main()
{
	int n=ri(),i,j;
	for(i=1;i<=n;i++)	a[i]=ri();
	sort(a+1,a+1+n);
	j=lower_bound(a+1,a+1+n,(a[n]+1)/2)-a;
	wi(a[n]);putchar(' ');
	if(j==1||fabs(0.5*a[n]-a[j-1])>fabs(0.5*a[n]-a[j])+1e-6)	wi(a[j]);
	else	wi(a[j-1]);
	putchar('\n');
	return 0;
}
/*
5
6 9 4 2 11







*/