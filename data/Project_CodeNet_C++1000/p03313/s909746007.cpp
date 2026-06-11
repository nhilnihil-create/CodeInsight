#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef pair<ll,ll> pll;
const int N = 18;
ll a[1<<N];
pll res[1<<N];
void merge(int x,int y)
{
	if(res[y].second>=res[x].first)
	{
		res[x].first = res[y].first;
		res[x].second = res[y].second;
	}
	else if(res[y].second<=res[x].first&&res[y].first>=res[x].first)
	{
		res[x].second = res[x].first;
		res[x].first = res[y].first;
	}
	else if(res[y].first<=res[x].first&&res[y].first>=res[x].second)
	{
		res[x].second = res[y].first;
	}
}
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<(1<<n);i++)	scanf("%lld",&a[i]);
	for(i=0;i<(1<<n);i++)
	{
		res[i].first = a[i];
		res[i].second = -1ll;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<(1<<n);j++)
		{
			if((j&(1<<i))==0)
			{
				merge(j|(1<<i),j);
			}
		}
	}
	ll ans = 0ll; 
	for(i=1;i<(1<<n);i++)
	{
		ans = max(ans,res[i].first+res[i].second);
		printf("%lld\n",ans);
	}
}
