#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#define ll long long
using namespace std;
 
const int N=300005;
const int inf=1000000000;
 
struct seg{
	int x,id;
	seg(){}
	seg(int x,int id):x(x),id(id){}
	friend bool operator<(seg a,seg b){
		if (a.x!=b.x) return a.x<b.x;
		return a.id<b.id;
	}
};
struct node{
	int l,r;
	node(){}
	node(int l,int r):l(l),r(r){}
}a[N];
int n,l,r,now,cnt,l1,l2,r1,r2,d1,d2,nx1,nx2,fir;
ll ans,sum;
bool vis[N];
set<seg> s1,s2;
set<seg>::iterator it;
 
ll solve(){
	int i;ll sum=0;
	s1.clear(); s2.clear();
	for (i=1;i<=n;i++){
		s1.insert(seg(a[i].r,i));
		s2.insert(seg(-a[i].l,i));
		vis[i]=0;
	}
	for (i=1;i<=n;i++){
		if ((i&1)!=(fir&1)){
			it=s1.begin();
			while (vis[(*it).id]){
				s1.erase(s1.find(*it));
				it=s1.begin();
			}
			vis[(*it).id]=1;
			l=a[(*it).id].l; r=a[(*it).id].r;
			if (now<l) sum+=1ll*abs(l-now),now=l;
			if (now>r) sum+=1ll*abs(now-r),now=r;
			s1.erase(it);
		}
		else{
			it=s2.begin();
			while (vis[(*it).id]){
				s2.erase(s2.find(*it));
				it=s2.begin();
			}
			vis[(*it).id]=1;
			l=a[(*it).id].l; r=a[(*it).id].r;
			if (now<l) sum+=1ll*abs(l-now),now=l;
			if (now>r) sum+=1ll*abs(now-r),now=r;
			s2.erase(it);
		}
	}
	sum+=1ll*abs(now);
	return sum;
}

int main(){
	int i,j;
	scanf("%d",&n);
	for (i=1;i<=n;i++){
		scanf("%d%d",&l,&r);
		a[i]=node(l,r);
	}
	fir=0; now=0;
	ans=solve();
	fir=1; now=0;
	ans=max(ans,solve());
	printf("%lld\n",ans);
	return 0;
}