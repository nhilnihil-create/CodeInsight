#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

typedef long long LL;

const int maxn=2e5+5, maxw=35;

int n;
multiset<int> v[maxw];
map<int,int> er;

int lowbit(int x) {return x&(-x);}

int find(int x)
{
	fd(i,30,0) if ((1<<i)&x) return 1<<i;
}

int main()
{
	fo(i,0,30) er[1<<i]=i;
	
	scanf("%d",&n);
	fo(i,1,n)
	{
		int x;
		scanf("%d",&x);
		v[er[lowbit(x)]].insert(x);
	}
	
	int ans=0;
	fo(i,0,30)
	{
		while (v[i].size()>=2)
		{
			multiset<int>::iterator it=v[i].end(); it--;
			int now=*it; v[i].erase(it);
			int need=((LL)find(now)<<1)-now;
			multiset<int>::iterator k=v[i].lower_bound(need);
			if (k!=v[i].end() && *k==need)
			{
				ans++;
				v[i].erase(k);
			}
		}
	}
	
	printf("%d\n",ans);
}