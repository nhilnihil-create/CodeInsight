#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,a[N],b[N],tot,now;
struct Tree{
	int l,r,num,flag;
}T[N*80];
inline int ef(int x){
	int l=1,r=tot;
	while (l<r){
		int mid=(l+r)/2;
		if (b[mid]<x)l=mid+1;
		else r=mid;
	}
	return l;
}
inline void build(int x,int l,int r){
	T[x].l=l;T[x].r=r;T[x].flag=-1;T[x].num=0;
	if (l==r)return;
	int mid=(l+r)/2;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
}
inline void down(int x){
	if (T[x].flag!=-1){
		T[x*2].flag=T[x*2].num=T[x].flag;
		T[x*2+1].flag=T[x*2+1].num=T[x].flag;
		T[x].flag=-1;
	}
}
inline void insert(int x,int l,int r,int z){
	if (T[x].l>r||l>T[x].r)return;
	if (T[x].l>=l&&T[x].r<=r){
		T[x].num=z;
		T[x].flag=z;
		return;
	}
	down(x);
	insert(x*2,l,r,z);
	insert(x*2+1,l,r,z);
	T[x].num=min(T[x*2].num,T[x*2+1].num);
}
inline void insert2(int x,int y){
	if (T[x].l==T[x].r){
		T[x].num++;
		return;
	}
	down(x);
	int mid=(T[x].l+T[x].r)/2;
	if (y<=mid)insert2(x*2,y);
	else insert2(x*2+1,y);
	T[x].num=min(T[x*2].num,T[x*2+1].num);
}
inline int find(int x,int l,int r){
	if (T[x].l>r||l>T[x].r)return 1e9;
	if (T[x].l>=l&&T[x].r<=r)return T[x].num;
	down(x);
	return min(find(x*2,l,r),find(x*2+1,l,r));
}
inline void Find(int x,int l,int r,int ans){
	if (T[x].l>r||l>T[x].r)return;
	if (T[x].l>=l&&T[x].r<=r){
		if (T[x].num<ans){
			if (now==-1||T[now].l<T[x].l)now=x;
		}
		return;
	}
	down(x);
	Find(x*2,l,r,ans);
	Find(x*2+1,l,r,ans);
}
inline int EF(int x,int ans){
	if (T[x].l==T[x].r)return T[x].l;
	down(x);
	if (T[x*2+1].num==ans)return EF(x*2,ans);
	return EF(x*2+1,ans);
}
inline int check(int ans){
	build(1,1,b[tot]);
	for (int i=1;i<=n;i++){
		if (i==1){
			insert(1,1,a[i],1);
			continue;
		}
		int x=a[i];
		if (x<a[i-1])insert(1,x+1,a[i-1],0);
		if (x>a[i-1]){
			insert(1,a[i-1]+1,x,1);
			continue;
		}
		now=-1;
		Find(1,1,x,ans);
		if (now==-1)return 0; 
		int l=EF(now,ans);
		insert(1,l+1,x,1);
		insert2(1,l);
	}
	return 1;
}
int main(){
	scanf("%d",&n);
	int ans=0;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]),b[++tot]=a[i];
	sort(b+1,b+tot+1);
	int num=1;
	for (int i=2;i<=n;i++)
		if (b[i]!=b[num])b[++num]=b[i];
	tot=num;
	for (int i=1;i<=n;i++)a[i]=ef(a[i]);
	int delta=0;
	for (int i=1;i<=tot;i++){
		b[i]-=delta;
		if (b[i]-b[i-1]>18){
			int k=b[i]-b[i-1]-18;
			delta+=k;
			b[i]-=k;
		}
	}
	for (int i=1;i<=n;i++)a[i]=b[a[i]];
	build(1,1,b[tot]);
	for (int i=1;i<=n;i++){
		if (i==1){
			ans=1;
			insert(1,1,a[i],1);
			continue;
		}
		int x=a[i];
		if (x<a[i-1])insert(1,x+1,a[i-1],0);
		if (x>a[i-1]){
			insert(1,a[i-1]+1,x,1);
			continue;
		}
		if (find(1,1,x)==ans)insert(1,x,x,++ans);
		else {
			now=-1;
			Find(1,1,x,ans);
			int l=EF(now,ans);
			insert(1,l+1,x,1);
			insert(1,l,l,find(1,l,l)+1);	
		}
	}
	int l=1,r=ans;
	while (l<r){
		int mid=(l+r)/2;
		if (check(mid))r=mid;
		else l=mid+1;
	} 
	printf("%d\n",l);
}