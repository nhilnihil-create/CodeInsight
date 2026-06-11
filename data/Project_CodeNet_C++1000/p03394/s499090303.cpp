#include<bits/stdc++.h>
using namespace std;

const int M=30000;
int n;

int a[M],A,b[M],B,c[M],C;
int main(){
#ifdef flukehn
	freopen("g.in","r",stdin);
#endif
	cin>>n;
	if(n==3)puts("2 5 63");
	else if(n==4)puts("2 5 20 63");
	if(n<=4)return 0;
	n-=5;
	printf("2 3 4 6 9 ");
	a[++A]=8;
	int i,m,t,x,y;
	for(i=10;i<=M;++i)
		if(i%6==0)c[++C]=i;
		else if(i%2==0)a[++A]=i;
		else if(i%3==0)b[++B]=i;
	m=min(n,C);
	if((n-m)%2)--m;
	for(i=1;i<=m;++i)
		printf("%d ",c[i]);
	if(!(n-=m))return 0;
	x=min(A,n),n-=x;
	for(i=1;i<=x;++i)
		printf("%d ",a[i]);
	for(i=1;i<=n;++i)
		printf("%d ",b[i]);
}