#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,a[200005],head=2,tail=4;
long long sum[200005],sa,sb,sc,sd,ans=(1ll<<60),mx,mn;
int main(){
	scanf("%d",&n);
	for(register int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	sa=a[1];sb=a[2];sc=a[3];sd=sum[n]-sum[3];
	for(register int i=3;i<=n;i++){
		while(head<i&&abs(sa-sb)>abs(sa-sb+2*a[head])){
			sa+=a[head];
			sb-=a[head];
			head++;
		}
		while(tail<=n&&abs(sd-sc)>abs(sc-sd+2*a[tail])){
			sc+=a[tail];
			sd-=a[tail];
			tail++;
		}
		mx=max(sa,max(sb,max(sc,sd)));
		mn=min(sa,min(sb,min(sc,sd)));
		ans=min(ans,mx-mn);
		sb+=a[i];
		sc-=a[i];
	}
	printf("%lld\n",ans);
	return 0;
}