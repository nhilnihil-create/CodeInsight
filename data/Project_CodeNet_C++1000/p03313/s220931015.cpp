#include<cstdio>
#include<algorithm>
using std::max;
int n,N,a[500100],ans[500100],maxn[500100];
int main(){
	scanf("%d",&n);N=(1<<n)-1;
	for(int i=0;i<=N;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<=N;i++)
		for(int j=i;j<=N;j=(j+1)|i)
			ans[j]=max(ans[j],maxn[j]+a[i]),maxn[j]=max(maxn[j],a[i]);
	for(int i=1;i<=N;i++)
		ans[i]=max(ans[i],ans[i-1]),printf("%d\n",ans[i]);
}