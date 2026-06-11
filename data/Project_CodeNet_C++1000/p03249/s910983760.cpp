#include <bits/stdc++.h>
#define int long long
using namespace std;

inline int read()
{
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
map<int,int> M1,M2,W1;
int s1[200010],pa[200010];
signed main()
{
	int n=read();
	for(int i=1;i<=n;i++)
	{
		int x=read();
		M1[x]=i; M2[x]=1;
		s1[i]=x; W1[x]=0;
	}
	sort(s1+1,s1+1+n);
	for(int i=n;i>1;i--)
	{
		int id=M1[s1[i]],sz=M2[s1[i]],td=s1[i]+2*sz-n;	
		if(td==s1[i]) continue;	
		pa[id]=M1[td]; M2[td]+=sz; W1[td]+=W1[s1[i]]+sz;
	}
	if(M2[s1[1]]!=n||W1[s1[1]]!=s1[1]) puts("-1"),exit(0);
	for(int i=1;i<=n;i++) if(pa[i])
		printf("%lld %lld\n",i,pa[i]);
	return 0;
}