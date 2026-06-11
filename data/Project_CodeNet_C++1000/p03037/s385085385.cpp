#include<cstdio>
int n,m;
int l,r;
int main() {
	scanf("%d %d",&n,&m);
	l=1,r=n;
	for(int i=1,u,v;i<=m;i++) {
		scanf("%d %d",&u,&v);
		if(u>l) l=u;
		if(v<r) r=v;
	}
	if(r<l) printf("0");
	else printf("%d",r-l+1);
	return 0;
}