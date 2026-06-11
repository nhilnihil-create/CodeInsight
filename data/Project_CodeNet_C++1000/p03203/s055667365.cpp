#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<set>
#include<vector>
#include<map>
#include<queue>

#define N 300005
#define M 8000005

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define mk make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;

int i,j,m,n,p,k,r,c,R[N];

vector<int>v[N];

long long ans,cnt;
int main()
{
		scanf("%d%d%d",&r,&c,&n);
		for (i=1;i<=n;++i)
		{
				int x,y;
				scanf("%d%d",&x,&y);
				v[y].pb(x);
		}
		for (i=1;i<=c;++i) v[i].pb(r+1),sort(v[i].begin(),v[i].end());
		R[1]=1;
		for (i=2;i<=c;++i)
		{
				for (j=min(r+1,R[i-1]+1);j<=r;++j)
				{
						int p=lower_bound(v[i].begin(),v[i].end(),j)-v[i].begin();
						if (p<(int)v[i].size()&&v[i][p]==j) continue;
						break; 
				}
				R[i]=j;
		}
		int ans=(int)1e9;
		for (i=1;i<=c;++i) 
		{
				int p=lower_bound(v[i].begin(),v[i].end(),R[i])-v[i].begin();
				ans=min(ans,v[i][p]);
		}
		printf("%d\n",ans-1);
}