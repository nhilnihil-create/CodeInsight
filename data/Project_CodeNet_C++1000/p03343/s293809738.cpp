#include<cstdio>
#include<algorithm>
int n,k,q,mi;
int a[2010],b[2010],ans[2001],cn,Ans=2147483647;
int main(){
	scanf("%d%d%d",&n,&k,&q);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		mi=a[i];
		int l=1,r=1;
		while(l<=n){
			while(a[l]<mi&&l<n) l++;
			r=l;
			while(a[r+1]>=mi&&r<n) r++;
			if(r-l+1>=k){
				for(int j=l;j<=r;j++) b[j]=a[j];
				std::sort(b+l,b+r+1);
				for(int j=l;j<=r-k+1;j++) ans[++cn]=b[j];
			}
			l=r+1;
		}
		std::sort(ans+1,ans+cn+1);
		if(cn>=q) if(ans[q]-ans[1]<Ans) Ans=ans[q]-ans[1];
		cn=0;
	}
	printf("%d\n",Ans);
	return 0;
}