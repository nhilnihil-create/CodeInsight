#include<bits/stdc++.h>
using namespace std;
#define RI register int
int read() {
	int q=0;char ch=' ';
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') q=q*10+ch-'0',ch=getchar();
	return q;
}
typedef long long LL;
const int N=100005,inf=0x3f3f3f3f;
int n,js,a[N],s[N],c[N];LL res,num;
void msort(int l,int r) {
	int mid=(l+r)>>1;
	for(RI k=l,i=l,j=mid+1;k<=r;++k)
		if(j>r||(i<=mid&&s[i]<=s[j])) c[k]=s[i++];
		else c[k]=s[j++];
	for(RI k=l;k<=r;++k) s[k]=c[k];
}
void work(int l,int r) {
	if(l==r) return;
	int mid=(l+r)>>1;
	work(l,mid),work(mid+1,r);
	for(RI i=l,j=mid+1;j<=r;++j) {
		while(i<=mid&&s[i]<=s[j]) ++i;
		res+=i-l;
	}
	msort(l,r);
}
int check(int x) {
	for(RI i=1;i<=n;++i) s[i]=s[i-1]+(a[i]>=x?1:-1);
	res=0,work(0,n);
	return res>=(num+1)/2;
}
int main()
{
	//freopen("median.in","r",stdin);
	//freopen("median.out","w",stdout);
	int l=inf,r=0,ans;
	n=read();num=1LL*n*(n-1)/2+n;
	for(RI i=1;i<=n;++i)
		a[i]=read(),l=min(a[i],l),r=max(a[i],r);
	while(l<=r) {
		int mid=(l+r)>>1;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}