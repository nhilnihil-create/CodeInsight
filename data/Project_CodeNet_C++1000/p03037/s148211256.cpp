#include <cstdio>
const int maxn = 1e5+5;
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
int n,m,l[maxn],r[maxn];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;++i)scanf("%d %d",&l[i],&r[i]);
	int L = 1,R = n;
	for(int i=1;i<=m;++i)
		L = max(l[i],L),R = min(r[i],R);
	printf("%d",max(0,R-L+1));
	return 0;
} 