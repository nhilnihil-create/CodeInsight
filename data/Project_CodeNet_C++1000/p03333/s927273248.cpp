#include<bits/stdc++.h>
using namespace std;
const int maxn=100100;
int n;
struct node{
	int l,r,id;
}a[maxn],b[maxn],c[maxn];
bool vis[maxn];
bool cmp1(const node &A,const node &B){
	return A.r<B.r;
}
bool cmp2(const node &A,const node &B){
	return A.l>B.l;
}
int Abs(int x){
	return x>0?x:-x;
}
long long solve(bool bo){
	memset(vis,0,sizeof(vis));
	int p=0,l1=1,l2=1;
	long long ans=0;
	while(1){
		if(bo){
			if(l2<=n&&vis[c[l2].id])
				l2++;
			if(l2>n) break;
			if(c[l2].l<=p) break;
			ans+=Abs(c[l2].l-p),p=c[l2].l;
			vis[c[l2].id]=1,l2++;
		}
		else{
			if(l1<=n&&vis[b[l1].id])
				l1++;
			if(l1>n) break;
			if(b[l1].r>=p) break;
			ans+=Abs(b[l1].r-p),p=b[l1].r;
			vis[b[l1].id]=1,l1++;
		}
		bo^=1;
	}
	ans+=Abs(p);
	return ans;
}
int main(){
//	freopen("C.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].l,&a[i].r);
		a[i].id=i;
	}
	for(int i=1;i<=n;i++)
		c[i]=a[i],b[i]=a[i];
	sort(b+1,b+n+1,cmp1);
	sort(c+1,c+n+1,cmp2);
	long long ans1=solve(0),ans2=solve(1);
	printf("%lld\n",ans1>ans2?ans1:ans2);
	return 0;
}
