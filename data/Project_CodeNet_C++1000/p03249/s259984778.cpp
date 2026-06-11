#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define N 350000
#include<map>
using namespace std;
struct node{
	long long x,id;
}a[N];
map<long long,long long>p;
long long n,siz[N],fa[N],ans;
int tot,Next[N],v[N],h[N];
int add(int x,int y){
	tot++;
	Next[tot]=h[x];
	v[tot]=y;
	h[x]=tot;
}
long long dfs(int x,int fa){
	siz[x]=1;
	for(int i=h[x];i;i=Next[i]){
		if(v[i]==fa)continue;
		dfs(v[i],x);
		ans+=siz[v[i]];
		siz[x]+=siz[v[i]];
	}
	return ans;
}
bool cmp(node x,node y){
	return x.x>y.x;
}
int main(){
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i].x);
		a[i].id=i;
	}
	sort(a+1,a+1+n,cmp);
	for(long long i=1;i<=n;i++){
		p[a[i].x]=a[i].id;
	}
	for(long long i=1;i<n;i++){
		long long x=a[i].id;
		p[a[i].x]=0;
		siz[x]++;
		long long o=a[i].x+siz[x]-(n-siz[x]);
	//	prlong longf("%d %d %d\n",a[i].x,o,siz[x]);
		long long l=p[o];
		if(l==0){
			printf("-1");
			return 0;
		}
		siz[l]+=siz[x];
		fa[x]=l;
		add(l,x);
		add(x,l);
	}
	fa[a[n].id]=0;
	memset(siz,0,sizeof(siz));
	if(dfs(a[1].id,0)!=a[1].x){
		printf("-1\n");
		return 0;
	}
	for(long long i=1;i<=n;i++){
		if(fa[i]!=0)printf("%lld %lld\n",i,fa[i]);
	}
} 