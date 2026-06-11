#include <bits/stdc++.h>
const int N=200005;
int c[N],d[N],a[N],b[N],mx,n,sum;
bool cmp(int x,int y){
	return x>y;
}
int solve(int x){
	for (int i=1;i<=n;i++) c[i]=a[i]%(x<<1),d[i]=b[i]%(x<<1);
	std::sort(c+1,c+n+1,cmp);
	std::sort(d+1,d+n+1);
	int pl1=1,pr1=0,pl2=1,pr2=1,ans=0;
	for (int i=1;i<=n;i++){
		long long t=c[i];
		while (d[pl1]+t<x && pl1<=n) pl1++;
		while (d[pr1+1]+t<2ll*x && pr1<n) pr1++;
		if (pr1>=pl1 && (pr1-pl1+1)&1) ans^=1;
		while (d[pl2]+t<3ll*x && pl2<=n) pl2++;
		while (d[pr2+1]+t<4ll*x && pr2<n) pr2++;
		if (pr2>=pl2 && (pr2-pl2+1)&1) ans^=1;
	}
	return ans*x;
}
int main(){
	scanf("%d",&n);
	int mx=0;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),mx=std::max(mx,a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]),mx=std::max(mx,b[i]);
	for (int i=0;(1<<i)<=(mx<<1);i++)
		sum+=solve(1<<i);
	printf("%d\n",sum);
} 