#include <bits/stdc++.h>
using namespace std;

inline int read()
{
	int x=0,f=1,c=getchar();
	while(c<48) c=='-'&&(f=-1),c=getchar();
	while(c>47) x=x*10+c-'0',c=getchar();
	return x*f;
}

typedef long long ll;
const int MAXN = 1005;
const char ch[4]= {'L','R','D','U'};
const int dx[4]= {-1,1,0,0},dy[4]= {0,0,-1,1};
std::vector<int> c;
int x[MAXN],y[MAXN],n;

int main(int argc, char const *argv[])
{
	n=read();
	for(int i=1; i<=n; ++i) 
		x[i]=read(),y[i]=read();
	for(int i=2; i<=n; ++i)
		if((abs(x[i]+y[i])&1)!=(abs(x[1]+y[1])&1))
			return puts("-1"),0;
	for(int i=30; ~i; --i) c.push_back(1<<i);
	if(!(abs(x[1]+y[1])&1)) c.push_back(1);
	printf("%lu\n",c.size());
	for(int i:c) printf("%d ",i); puts("");
	for(int i=1; i<=n; ++i)
	{
		ll nx=0,ny=0;
		for(int j:c)
		{
			vector<pair<ll,int>> tmp;
			for(int d=0; d<4; ++d)
			{
				ll tx=nx+dx[d]*j,ty=ny+dy[d]*j;
				tmp.push_back(make_pair(abs(x[i]-tx)+abs(y[i]-ty),d));
			}
			sort(tmp.begin(),tmp.end());
			int d=tmp.begin()->second;
			putchar(ch[d]),nx+=dx[d]*j,ny+=dy[d]*j;
		}
		puts("");
	}
	return 0;
}