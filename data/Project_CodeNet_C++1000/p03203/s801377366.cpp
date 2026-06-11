#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#define ll long long
using  namespace std;
template <class T>
inline void read(T &x)
{
   x=0; char c=getchar(); int f=1;
   while(!isdigit(c)){if(c=='-')f=-1; c=getchar();}
   while(isdigit(c)) x=x*10-'0'+c,c=getchar(); x*=f;
}
const int N=2e5+10;
set<int> s[N];
int n,m,tot;
int main()
{
	int x,y; read(n),read(m),read(tot);
	for(int i=1;i<=tot;i++) read(x),read(y),s[x].insert(y);
//	for(int i=1;i<=n;i++,puts(""))
//		for(int j=1;j<=m;j++) putchar(s[i].count(j)?'0':'1');
	
	for(int i=1;i<=n;i++) s[i].insert(m+1);
	int p=1,ans=n;
	for(int i=1;i<n;i++)
	{
		if(s[i+1].upper_bound(p)!=s[i+1].begin()) {ans=i; break;}
		if(!s[i+1].count(p+1)) p++;
//		printf("%d %d\n",i,p);
	}
	printf("%d",ans);
	return 0;
}