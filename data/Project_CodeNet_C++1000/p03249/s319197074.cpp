/*
题意：问能否构造出一棵树，使得对于某点i，到其他所有点的距离和为Di。Di各不相同。 
如果已知x的size，那么x的父亲的Di=Dx-n+2*size[x],唯一还原
我们需要从底往上构造
由于一棵树一定有一个点到其他所有点的距离最小，其余点离此点距离越远，Di越大
将Di从大到小排序，父亲一定在儿子之后被统计 
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
const int N=100005;
int n,size[N],fa[N];
map<ll,int> mp;
struct node{int id;ll dis;}p[N];
bool cmp(const node &A,const node &B){return A.dis>B.dis;}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&p[i].dis),p[i].id=i,mp[p[i].dis]=i;
	sort(p+1,p+n+1,cmp);
	for (int i=1;i<n;i++)
	{
		size[p[i].id]++;
		ll fa_Di=p[i].dis-n+2*size[p[i].id];
		if (!mp.count(fa_Di)) return puts("-1"),0;else fa[p[i].id]=mp[fa_Di];
		if (fa[p[i].id]==p[i].id) return puts("-1"),0;
		size[fa[p[i].id]]+=size[p[i].id];
	}
	for (int i=1;i<n;i++) p[n].dis-=size[p[i].id];
	if (p[n].dis) return puts("-1"),0;
	for (int i=1;i<=n;i++) 
	  if (fa[i]) printf("%d %d\n",i,fa[i]); 
	return 0;
}