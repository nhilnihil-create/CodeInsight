#include<bits/stdc++.h>
using namespace std;

typedef long long lint;
typedef long double louble;

template<typename T1,typename T2> inline T1 max(T1 a,T2 b){return a<b?b:a;}
template<typename T1,typename T2> inline T1 min(T1 a,T2 b){return a<b?a:b;}

namespace ae86
{
	const int bufl = 1<<15;
	
	char buf[bufl],*s=buf,*t=buf;
	
	inline int fetch()
	{
		if(s==t){t=(s=buf)+fread(buf,1,bufl,stdin);if(s==t)return EOF;}
		return *s++;
	}
	
	inline int ty()
	{
		int a=0,b=1,c=fetch();
		while(!isdigit(c))b^=c=='-',c=fetch();
		while(isdigit(c))a=a*10+c-48,c=fetch();
		return b?a:-a;
	}
}
using ae86::ty;

const int _ = 103;

vector<int> p[_];int np=0;
vector<pair<int,int>> ans;

int main()
{
	int n=ty();
	if(n&1)
	{
		np=n/2+1;
		for(int i=1;i<np;i++)p[i].emplace_back(i),p[i].emplace_back(n-i);
		p[np].emplace_back(n);
	}
	else
	{
		np=n/2;
		for(int i=1;i<=np;i++)p[i].emplace_back(i),p[i].emplace_back(n-i+1);
	}

	for(int i=1;i<=np;i++)
		for(int j=i+1;j<=np;j++)
			for(auto a:p[i])
				for(auto b:p[j])
					ans.emplace_back(a,b);
	printf("%lu\n",ans.size());
	for(auto i:ans)printf("%d %d\n",i.first,i.second);
	
	return 0;
}
