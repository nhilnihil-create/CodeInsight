#include<cstdio>
#include<algorithm>
int n,K,Q,flag[200100],val[200100],A[200100],b[200100],ans=0x3f3f3f3f;
using std::sort;
struct node{
	int val,id;
	bool operator<(node b)const{
		return val<b.val;
	}
}a[200100];
int main(){
	scanf("%d%d%d",&n,&K,&Q);
	for(int i=1;i<=n;i++)
		scanf("%d",&val[i]),a[i].val=val[i],a[i].id=i;
	sort(a+1,a+n+1);
	flag[0]=flag[n+1]=1;
	for(int i=1;i<=n-Q+1;i++){
		flag[a[i-1].id]=1;
		int cnt=0;
		for(int j=1,sum=0;j<=n+1;j++)
			if(!flag[j])A[++sum]=val[j];
			else{
				if(sum==0)continue;
				sort(A+1,A+sum+1);
				for(int k=1;k<=sum-K+1;k++)
					b[++cnt]=A[k];
				sum=0;
			}
		if(cnt<Q)break;
		sort(b+1,b+cnt+1);
		ans=std::min(ans,b[Q]-b[1]);
	}
	printf("%d\n",ans);
}