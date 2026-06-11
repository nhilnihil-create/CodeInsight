#include<bits/stdc++.h>
using namespace std;
const int N=200005;
typedef long long ll;
ll read(){
	ll x=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1; ch=getchar();	}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
ll a[N],b[N],s[N],n,pre[N];
set<int>sx;
map<int,int>mp;
struct BIT{
	ll s[N],m;
	ll lowbit(ll x){
		return x&(-x);
	}
	void clear(){
		for (ll i=0;i<=m;i++) s[i]=0;
	}
	void modify(ll x,ll y){
		for (ll i=x;i<=m;i+=lowbit(i)) s[i]+=y;
	}
	ll query(ll x){
		ll ans=0;
		for (ll i=x;i;i-=lowbit(i)) ans+=s[i];
		return ans;
	}
}tree;
ll calc(ll mid){
	s[0]=0; tree.clear(); tree.modify(n,1);
	ll ans=0;
	for (ll i=1;i<=n;i++){
		if (a[i]<=mid) s[i]=s[i-1]+1;
		else s[i]=s[i-1]-1;
		ans+=tree.query(n+s[i]-1);
		tree.modify(n+s[i],1);
	}
	return ans;
}
int main(){
	n=read();
	for (ll i=1;i<=n;i++) a[i]=read(),sx.insert(a[i]);
	ll cnt=0;
	for (set<int>::iterator it=sx.begin();it!=sx.end();it++) 
	mp[*it]=++cnt,pre[cnt]=*it;
	tree.m=2*n;
	for (ll i=1;i<=n;i++) a[i]=mp[a[i]];
	ll l=1,r=cnt,ans=0;
	ll x=n*(n+1)/4;
	while (l<=r){
		ll mid=(l+r)>>1;
		if (calc(mid)>x) ans=mid,r=mid-1; else l=mid+1;
	}
	ans=pre[ans];
	printf("%lld\n",ans);
	return 0;
}