#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int read(){
	int x=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1; ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
int ans=0,cnt,a[N],b[N],d[N],s[N],c[N],n,k,q;
bool ck(int x,int mid){
	s[0]=0; int tot=0;
	for (int i=1;i<=n;i++){
	if (a[i]<x) b[i]=0,d[++tot]=i;
	if (a[i]>=x&&a[i]<=mid) b[i]=1;
	if (a[i]>mid) b[i]=2;
	if (b[i]==1) s[i]=s[i-1]+1; else s[i]=s[i-1];
	}
	int cnt=0; d[0]=0;
	d[++tot]=n+1;
	for (int i=1;i<=tot;i++){
		int l=d[i-1]+1,r=d[i]-1;
		if (l>r) continue;
		if (r-l+1<k) continue;
		cnt+=min(s[r]-s[l-1],r-l+2-k);
	}
	return (cnt>=q);
}
int main(){
	n=read(),k=read(),q=read();
	for (int i=1;i<=n;i++) a[i]=read(),c[i]=a[i];
	ans=1e9;
	sort(c+1,c+1+n);
	for (int i=1;i<=n;i++){
		cnt=1e9;
		int l=i,r=n;
		while (l<=r){
			int mid=(l+r)>>1;
			if (ck(c[i],c[mid])) cnt=min(cnt,c[mid]-c[i]),r=mid-1; else l=mid+1;
		}
		ans=min(ans,cnt);
	}
	printf("%d\n",ans);
}