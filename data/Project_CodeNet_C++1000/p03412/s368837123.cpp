#include<bits/stdc++.h>
using namespace std;

const int maxn=2e5+100;

int a[maxn],b[maxn],c[maxn],n;

int want(int x){
	for(int i=1;i<=n;i++) c[i]=b[i]%(x*2);
	sort(c+1,c+n+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		int k=a[i]%(x*2);
		int f1,f2;
		f1=lower_bound(c+1,c+n+1,x*2-k)-1-lower_bound(c+1,c+n+1,x-k);
		f2=lower_bound(c+1,c+n+1,4*x-k)-1-lower_bound(c+1,c+n+1,3*x-k);
		ans+=f1+f2;
	}
	if(ans%2==0) return 0;
	else return 1;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	int ans=0;
	for(int i=0;i<=28;i++) ans+=want(1<<i)*(1<<i);
	printf("%d",ans);
	return 0;
}