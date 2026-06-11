#include<cstdio>
#include<vector>
#include<set>
#define RI register int
#define CI const int&
using namespace std;
int n,x,ans; multiset <int> s; vector <int> tp;
int main()
{
	RI i; for (scanf("%d",&n),i=1;i<=n;++i) scanf("%d",&x),s.insert(x);
	for (i=(1<<30);i>1;i>>=1)
	{
		tp.clear(); while (s.size()>=2)
		{
			multiset <int>:: iterator it=s.end(); x=*(--it);
			if (x>=i) { s.erase(it); continue; } s.erase(it);
			if (s.count(i-x)) ++ans,s.erase(s.find(i-x)); else tp.push_back(x);
		}
		for (vector <int>:: iterator it=tp.begin();it!=tp.end();++it) s.insert(*it);
	}
	return printf("%d",ans),0;
}