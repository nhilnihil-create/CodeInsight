#include <iostream>
#include <vector>
using namespace std;
vector<pair<pair<int,int>,int> > e;
int main()
{
	int l,p=0;
	scanf("%d",&l);
	while ((1<<p)<=l)
	p++;
	int cur=(1<<(p-1));
	for (int i=1;i<p;i++)
	{
		e.push_back({{i,i+1},0});
		e.push_back({{i,i+1},(1<<(i-1))});
	}
	for (int i=p-1;i>0;i--)
	{
		if (cur+(1<<(i-1))<=l)
		{
			e.push_back({{i,p},cur});
			cur+=(1<<(i-1));
		}
	}
	printf("%d %d\n",p,e.size());
	for (auto p:e)
	printf("%d %d %d\n",p.first.first,p.first.second,p.second);
}