#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<stack>
#define LL long long
using namespace std;
string f;
int a[100011];
int n;
int ans;
int read()
{
	int _=0,__=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')__=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){_=_*10+ch-'0';ch=getchar();}
	return _*__;
}
int main()
{
	cin>>f;
	n=f.size();
	ans=f.size();
	for(int i=0;i<n;i++)
	a[i]=f[i]-'0';
	for(int i=1;i<n;i++)
	if(a[i]!=a[i-1])
	ans=min(ans,max(i,n-i));
	printf("%d\n",ans);
	return 0;
}