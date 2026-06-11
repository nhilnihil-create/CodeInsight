#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long
template <class T>
inline void read(T &x)
{
   x=0; char c=getchar(); int f=1;
   while(!isdigit(c)){if(c=='-')f=-1; c=getchar();}
   while(isdigit(c)) x=x*10-'0'+c,c=getchar(); x*=f;
}
const int N=2e5+10;
int a[N];
int pos[N],num[N],top,n;
bool che(int b)
{
	top=0;
	for(int i=2;i<=n;i++)
	if(a[i]<=a[i-1])
	{
		int tmp=a[i];
		while(top&&pos[top]>tmp) top--;
		while(top&&tmp&&pos[top]==tmp&&num[top]==b-1) tmp--,top--;
		if(tmp==0) return 0;
		if(pos[top]<tmp){ pos[++top]=tmp,num[top]=1; if(b<2) return 0;}
		else num[top]++;
	}
	return 1;
}
int main()
{
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	int l=1,r=n;
	while(l<r)
	{
		int mid=l+r>>1;
		if(che(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d",r);
	return 0;
}