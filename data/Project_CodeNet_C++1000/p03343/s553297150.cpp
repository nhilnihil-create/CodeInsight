#include<cstdio>
#include<algorithm>
int n,k,q,a[2005];
int ls[2005],st[2005],con;
int work(int mini){
	int last=-1;
	con=0;
	for(int i=1;i<=n;i++) ls[i]=a[i];
	for(int i=1;i<=n+1;i++){
		if(a[i]>=mini&&last==-1) last=i;
		if(a[i]<mini&&~last){
			std::sort(ls+last,ls+i);
			for(int j=last;j<=i-k;j++) st[con++]=ls[j];
			last=-1;
		}
	}
	if(con<q) return 0x3f3f3f3f;
	std::sort(st,st+con);
	return st[q-1]-mini;
}
int main(){
	scanf("%d%d%d",&n,&k,&q);
	a[n+1]=-1;
	int ans=0x3f3f3f3f;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		ans=std::min(ans,work(a[i]));
	printf("%d\n",ans);
}