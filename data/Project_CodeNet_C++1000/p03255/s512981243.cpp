#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
#include<iostream>
#include<cmath>
#define LL long long
#define N (200005)
using namespace std;
int n,tt;
LL a[N],sum[N];
LL ans=9e18,x,now; 
template <typename T> void read(T&t) {
	t=0;
	bool fl=true;
	char p=getchar();
	while (!isdigit(p)) {
		if (p=='-') fl=false;
		p=getchar();
	}
	do {
		(t*=10)+=p-48;p=getchar();
	}while (isdigit(p));
	if (!fl) t=-t;
}
int main(){
	read(n),read(x);
	for (int i=1;i<=n;i++) read(a[i]),sum[i]=sum[i-1]+a[i];
	for (int i=1;i<=n;i++){
		now=x*(i+n);
		tt=3;
		for (int j=n;j>=1;j-=i){
			if (tt==3) now+=(sum[j]-sum[max(0,j-i)])*5;
			else now+=(sum[j]-sum[max(0,j-i)])*tt;
			tt+=2;
			if (now>=ans) break; 
		}
		ans=min(ans,now);
	}
	printf("%lld",ans);
	return 0;
}
