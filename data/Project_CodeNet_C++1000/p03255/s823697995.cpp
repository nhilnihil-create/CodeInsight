#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize(4)
#pragma GCC optimize("Ofast,no-stack-protector")
#include <bits/stdc++.h>
#define ll long long
#define res register ll
#define N 200005
#define inf 0x3f3f3f3f
#define mod 1000000007
ll a[N],n,m,sum[N],ans=2e18,total;
using namespace std;
inline ll read(){
	res w=0,X=0;register char ch=0;
	while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
	while(isdigit(ch)){X=(X<<1)+(X<<3)+(ch^48);ch=getchar();}
	return w?-X:X;
}
int main(){
	n=read(),m=read();
	for(res i=1;i<=n;i++)
	  a[i]=read(),sum[i]=sum[i-1]+a[i];
	for(res i=1;i<=n;i++){
		res tmp=3LL;
		total=0;
		for(res j=n;j>=1;j-=i){
			total+=(sum[j]-sum[max(j-i,0LL)])*max(tmp,5LL);
			tmp+=2;
			if(total>=ans) break;
		}
		ans=min(ans,total+m*(n+i));
	}
	printf("%lld\n",ans);
	return 0;
}