#include<bits/stdc++.h>
#define rep(X,A,B) for(int X=A;X<=B;X++)
#define tep(X,A,B) for(int X=A;X>=B;X--)
#define LL long long
#define DB double
const int N=400010;
const int M=800010;
using namespace std;

int n;
map<LL,int> mp;
LL sz[N];
int fa[N],edge[M],lst[N],nxt[M],t=0;

struct nn{
	LL d;
	int id;
}a[N];

int cmp(nn A,nn B){
	return A.d<B.d;
}

void READ(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%lld",&a[i].d),a[i].id=i,mp[a[i].d]=i;
	sort(a+1,a+n+1,cmp);
}

void ADD(int x,int y){
	edge[++t]=y;nxt[t]=lst[x];lst[x]=t;
}

LL SEARCH(int x,int dep){
	LL res=dep;
	for(int r=lst[x];r;r=nxt[r]){
		res+=SEARCH(edge[r],dep+1);
	}
	return res;
}

int SOLVE(){
	rep(i,1,n)sz[i]=1;
	tep(i,n,2){
		int x=a[i].id;
		LL d=a[i].d;
		LL now=d+2*sz[x]-n;
		int pos=mp[now];
		if(pos==0||now>=a[i].d)return 0;
		fa[x]=pos;
		ADD(fa[x],x);
		sz[fa[x]]+=sz[x];
	}
	LL sum=SEARCH(a[1].id,0);
	if(sum!=a[1].d)return 0;
	rep(i,1,n){
		if(i==a[1].id)continue;
		printf("%d %d\n",i,fa[i]);
	}
	return 1;
}

int main(){
	READ();
	if(!SOLVE())printf("-1\n");
	return 0;
}