#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=6000000;
int k,tot=0,f[N];
LL a[N];
double calc(LL x){
	LL y=x,z=0;
	while (y)
		z+=y%10,y/=10;
	return 1.0*x/z;
}
int main(){
	for (LL i=1,v=1;i<=15;i++,v*=10)
		for (int j=2;j<=1000;j++)
			a[++tot]=v*j-1;
	sort(a+1,a+tot+1);
	tot=unique(a+1,a+tot+1)-a-1;
	memset(f,0,sizeof f);
	double mx=1e16;
	for (int i=tot;i>=1;i--){
		double x=calc(a[i]);
		if (x>mx)
			f[i]=1;
		else
			mx=x;
	}
	scanf("%d",&k);
	for (int i=1,j=1;i<=k;i++,j++){
		while (f[j])
			j++;
		printf("%lld\n",a[j]);
	}
	return 0;
}