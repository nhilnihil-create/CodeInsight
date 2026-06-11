#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define MN 200005
using namespace std;
typedef unsigned long long ull;
int n,a[MN];
ull m,sum[MN];
int main(){
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i];
	ull ans=m*n+sum[n]*5;
	for(int i=1;i<n;i++){
		ull tmp=m*i;
		if(i*2<=n){
			tmp+=(sum[n]-sum[n-2*i])*5;
			int ttmp=7,pre=n-2*i;
			while(pre>=i){
				tmp+=(sum[pre]-sum[pre-i])*ttmp,ttmp+=2;pre-=i;
			}tmp+=(sum[pre])*ttmp;
		}else tmp+=sum[n]*5;
		ans=min(ans,tmp);
	}printf("%lld\n",ans+m*n);
}
