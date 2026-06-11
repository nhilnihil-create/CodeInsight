#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<iostream>
#include<algorithm>
#define N 200001
#define LL long long
#define LOG(x) cerr<<#x<<" = "<<x<<endl
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;
}
using namespace std;
int n,a[N];
bool check(int m)
{
	// cerr<<m<<endl;
	static map<int,int> s;
	s.clear();
	for(int i=2;i<=n;++i)
	{
		if(a[i-1]>=a[i])
		{
			while(!s.empty() && s.rbegin()->first>a[i])
				s.erase(--s.end());
			for(int j=a[i];~j;--j)
			{
				if(!j)return 0;
				++s[j];
				if(s[j]==m)s.erase(j);
				else break;
			}
		}
	}
	return 1;
}
int main()
{
	re(n);
	bool ok=1;
	for(int i=1;i<=n;++i)re(a[i]),ok&=a[i-1]<a[i];
	if(ok)
	{
		puts("1");
		return 0;
	}
	int l=2,r=n;
	while(l < r)
	{
		int m=l+r>>1;
		if(check(m))r=m;
		else l=m+1;
	}
	printf("%d\n",l);
}
/*
aaaaa aaab aab
*/
