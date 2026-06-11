#include<cstdio>
#include<cstring>
#include<map>
#include<queue>
#include<iostream>
#include<algorithm>
#define maxn 100050
using namespace std;
typedef long long LL;

int n;
LL D[maxn];

int pos[maxn];

LL ans[maxn];

LL size[maxn];

map<LL,int> mp;

void init()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	{
		pos[i]=i;
		scanf("%lld",&D[i]); 
		mp[D[i]]=i;
	}
}

int fa[maxn];

bool vis[maxn];

bool cmp(int i,int j)
{
	return D[i]>D[j];
}

int find(LL x)
{
	return mp.count(x)?mp[x]:0;
}

bool solve()
{
	sort(pos+1,pos+n+1,cmp);
	for (int k=1;k<n;++k)
	{
		
		int i=pos[k],j=find(D[i]+2LL*++size[i]-n);
//		cout<<"out:"<<i<<" "<<ans[i]<<endl;
		
		vis[i]=1;
//		cout<<i<<" "<<j<<" "<<D[i]+2LL*size[i]-n<<endl;
		if (!j||vis[j])
			return 0;
		fa[i]=j;
		size[j]+=size[i];
		ans[j]+=ans[i]+size[i];
	}
	
//	cout<<ans[pos[n]]<<" "<<D[pos[n]]<<endl;
	if (ans[pos[n]]!=D[pos[n]])
		return 0;
//	puts("YES");
	for (int k=1;k<=n;++k)
	{
		int u=pos[k];
		if (fa[u])
			printf("%d %d\n",u,fa[u]);
	}
	return 1;
}

int main()
{
//    freopen("c.in","r",stdin);
//    freopen("c.out","w",stdout);
    init();
    if (!solve())
    	printf("-1\n");
    return 0;
}