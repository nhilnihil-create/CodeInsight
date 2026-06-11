#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

typedef long long LL;

const int maxn=2e5+5;

int n,m,dr[maxn];
char s[maxn],inD[maxn];

char Read()
{
	char ch=getchar();
	while (ch<'A' || ch>'Z') ch=getchar();
	return ch;
}

int check(int x)
{
	fo(i,1,m) if (s[x]==inD[i])
	{
		x+=dr[i];
		if (x<1 || x>n) break;
	}
	return x;
}

int main()
{
	scanf("%d %d",&n,&m);
	scanf("%s",s+1);
	fo(i,1,m)
	{
		char ch1=Read(),ch2=Read();
		inD[i]=ch1;
		dr[i]=(ch2=='L') ?-1 :1 ;
	}
	
	int l=1, r=n;
	while (l<=r)
	{
		int mid=(l+r)>>1;
		if (check(mid)==0) l=mid+1; else r=mid-1;
	}
	int ans1=l-1;
	
	l=1, r=n;
	while (l<=r)
	{
		int mid=(l+r)>>1;
		if (check(mid)==n+1) r=mid-1; else l=mid+1;
	}
	int ans2=r+1;
	
	printf("%d\n",max(0,ans2-1-ans1));
}