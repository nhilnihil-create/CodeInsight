#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
typedef pair <P,int> PP;

int main()
{
	int L;
	scanf("%d",&L);
	int now=1,t=0;
	while(now<=L) now<<=1,t++;
	vector <PP> edge;
	for(int i=0;i+1<t;i++)
	{
		edge.push_back(PP(P(i,i+1),1<<i));
		edge.push_back(PP(P(i,i+1),0));
	}
	int zan=1<<(t-1);
	for(int i=t-2;i>=0;i--)
	{
		if(L>>i&1)
		{
			edge.push_back(PP(P(i,t-1),zan));
			zan+=1<<i;
		}
	}
	printf("%d %d\n",t,edge.size());
	for(int i=0;i<edge.size();i++)
	{
		P p=edge[i].first;
		printf("%d %d %d\n",p.first+1,p.second+1,edge[i].second);
	}
	return 0;
}
