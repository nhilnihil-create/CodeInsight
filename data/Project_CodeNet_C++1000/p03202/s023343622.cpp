
#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
const int maxn=2e5+10;
map<int,int> pos;
int n;
int a[maxn];
bool check(int mxnum)
{
	pos.clear();
	for(int i=0;i<n;i++)
	{
		if(!i||a[i]>a[i-1])continue;
		int here=a[i];
		while(here>=1&&pos.count(here)&&pos[here]==mxnum-1)
		{
			pos.erase(here);
			here--;
		}
		if(here<1)return 0;
		if(!pos.count(here))pos[here]=1;
		else pos[here]++;
		if(pos[here]>=mxnum)return 0;
		for(map<int,int>::iterator it=pos.begin();it!=pos.end();)
			if(it->first>here)
			{
				map<int,int>::iterator tmp=it;
				it++;
				pos.erase(tmp);
			}
			else it++;
	}
	return 1;
}
int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	int l=0,r=n;
	while(r-l>1)
	{
		int mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid;
	}
	printf("%d\n",r);
	return 0;
}