#include<cstdio>
#include<algorithm>
typedef long long ll;
const int MaxN=100010;
int N,V[MaxN],fa[MaxN],siz[MaxN];
ll D[MaxN];
bool cmp(int i,int j){return D[i]<D[j];}
int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++)scanf("%lld",D+i),V[i-1]=i;
	std::sort(V,V+N,cmp);
	ll D0=0;
	for(int*i=V+N;--i>V;){
		D0+=siz[*i]++;
		D[*i]-=N-2*siz[*i];
		int*j=std::lower_bound(V,i,*i,cmp);
		if(j<i&&D[*j]==D[*i])siz[fa[*i]=*j]+=siz[*i];
		else return puts("-1"),0;
	}
	if(D0+N-1!=D[*V])return puts("-1"),0;
	for(int*i=V+N;--i>V;)printf("%d %d\n",*i,fa[*i]); 
}