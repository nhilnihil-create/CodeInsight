#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<math.h>
#include<set>
using namespace std;

const int N=3e5+5;
int h,w,n,ans[N];
pair<int,int> p[N];
set<int> S[N];

int main()
{
	int i,pr;
	scanf("%d%d%d",&h,&w,&n);
	pr=h;
	for(i=1;i<=n;++i)
	{
		scanf("%d%d",&p[i].first,&p[i].second);
		S[p[i].second].insert(p[i].first);
	}
	
	ans[1]=1;
	for(i=2;i<=w;++i)
	{
		ans[i]=ans[i-1]+1;
		set<int>::iterator it;
		for(it=S[i].begin();it!=S[i].end();++it)
			if((*it)==ans[i])
				++ans[i];
	}
	
	for(i=1;i<=n;++i)
		if(ans[p[i].second]<p[i].first)
			pr=min(pr,p[i].first-1);
	
	printf("%d\n",pr);
	return 0;
}