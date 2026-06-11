#include <algorithm>
#include <cstdio>
#include <map>

int n;
struct point{
	long long D;
	int id;
}num[100001];
std::map<long long,int>map;
int size[100001],fa[100001],dep[100001];
bool cmp(const point &a,const point &b){return a.D>b.D;}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&num[i].D),num[i].id=map[num[i].D]=i,size[i]=1;
	std::sort(num+1,num+n+1,cmp);
	for(int i=1;i<n;i++)
		if(!(fa[i]=map[num[i].D+(size[num[i].id])-(n-size[num[i].id])])||(fa[i]==num[i].id))
			{puts("-1");return 0;}
		else size[fa[i]]+=size[num[i].id];
	for(int i=n-1;i;i--)num[n].D-=(dep[num[i].id]=dep[fa[i]]+1);
	if(num[n].D){puts("-1");return 0;}
	for(int i=1;i<n;i++)printf("%d %d\n",fa[i],num[i].id);
}