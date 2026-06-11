#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
int pre[200010],n,x,minn; 
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&x);
		pre[i]=pre[i-1]+x;
	}
	int p1=1,p2=2,p3=3;
	long long ans=1e18;
	for(;p2<n;p2++){
		int minn=1e18,maxn=0;
		for(int i=p1;i<p2;i++)
			if(abs(pre[i]-(pre[p2]-pre[i]))<minn){
				minn=abs(pre[i]-(pre[p2]-pre[i]));
				p1=i;
			}
			else break;
		minn=1e18;
		if(p3<=p2)p3=p2+1;
		for(int i=p3;i<=n;i++)
			if(abs((pre[i]-pre[p2])-(pre[n]-pre[i]))<minn){
				minn=abs((pre[i]-pre[p2])-(pre[n]-pre[i]));
				p3=i;
			}
			else break;
		minn=1e18;
		minn=min(pre[p1],min(pre[p2]-pre[p1],min(pre[p3]-pre[p2],pre[n]-pre[p3])));
		maxn=max(pre[p1],max(pre[p2]-pre[p1],max(pre[p3]-pre[p2],pre[n]-pre[p3])));
		ans=min(ans,maxn-minn);		
	}
	printf("%lld\n",ans);
}