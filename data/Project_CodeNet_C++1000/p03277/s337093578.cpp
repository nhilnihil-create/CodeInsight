#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
inline int lowbit(int x){return x&-x;}
long long tr[N],a[N],d[N];
long long n,m;
int query(int x){
	int ans=0;
	while (x){
		ans+=tr[x];
		x-=lowbit(x);
	}
	return ans;
}
void add(int x,int k){
	while (x<=n+n+1){
		tr[x]+=k;
		x+=lowbit(x);
	}
}
bool check(int x){
	long long tot=0;
	memset(tr,0,sizeof tr);
	d[0]=n+1;
	for (int i=1;i<=n;++i){
		if (a[i]<x) d[i]=-1;
		else d[i]=1;
		d[i]+=d[i-1];
	}
	add(d[0],1);
	for (int i=1;i<=n;++i){
		tot+=query(d[i]);
		add(d[i],1);
	}
	return (tot>=m/2);
}
int main(){
	scanf("%d",&n);
	m=(n+1)*n/2;
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	if (n==1){printf("%d\n",a[1]);return 0;}
	int l=1,r=1e9;
	while (l<r){
		int mid=(l+r+1)>>1;
		if (check(mid)) l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
}

