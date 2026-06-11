#include <iostream>
#include <set>
using namespace std;
int mx[(1<<18)];
multiset<int> s[(1<<18)];
void add(int a,int b)
{
	s[a].insert(b);
	if (s[a].size()>2)
	s[a].erase(s[a].begin());
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<(1<<n);i++)
	{
		int a;
		scanf("%d",&a);
		s[i].insert(a);
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<(1<<n);j++)
		{
			if (!(j&(1<<i)))
			{
				for (int k:s[j])
				add((j|(1<<i)),k);
			}
		}
	}
	for (int i=1;i<(1<<n);i++)
	{
		mx[i]=max(mx[i-1],*s[i].begin()+*next(s[i].begin()));
		printf("%d\n",mx[i]);
	}
}