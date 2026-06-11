//by xxj
//I love 7 sea 1e3 fall
#include<bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
#define mp make_pair
#define ll long long
#define pii pair<int,int>
#define lowbit(x) x&-x
const int inf=1e9+7;
const double eps=1e-10;
const ll linf=1e18+7;
const ll hh=523;
//const int mod=;
inline int read(){
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x;
}
int mx=2e5+7;
int pow(int a,int c){
	int re=1;
	while (c){
		if (c&1){
			if (1ll*re*a>=mx){
				return mx;
			}
			re*=a; 
		}
		c>>=1;
		if (c && 1ll*a*a>=mx){
			return mx;
		}
		a*=a;
	}
	return re;
}
int ls[200007];
int a[200007];
map<int,int> lsh;
int hve[200007],dat[1600007];
bool lazy[1600007];
int add[1600007];
int le[1600007],ri[1600007],len[1600007];
int n;
int cnt=0;
void build(int l,int r,int id){
	le[id]=l;
	ri[id]=r;
	len[id]=r-l+1;
	lazy[id]=false;
	add[id]=0;
	if (l==r){
		dat[id]=0;
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,id*2);
	build(mid+1,r,id*2+1);
	dat[id]=0;
	return;
}
inline void push_down(int id){
	if (lazy[id]){
		dat[id*2]=0;
		dat[id*2+1]=0;
		lazy[id*2]=true;
		lazy[id*2+1]=true;
		add[id*2]=0;
		add[id*2+1]=0;
		lazy[id]=false;
	}
	if (add[id]){
		dat[id*2]+=add[id]*len[id*2];
		dat[id*2+1]+=add[id]*len[id*2+1];
		add[id*2]+=add[id];
		add[id*2+1]+=add[id];
		add[id]=0;
	}
}
inline int query(int p,int id){
	int l1=le[id],r1=ri[id];
	if (l1==r1){
		return dat[id];
	}
	push_down(id);
	if (p<=ri[id*2]){
		return query(p,id*2);
	}
	else{
		return query(p,id*2+1);
	}
}
inline void xgqj(int l,int r,int id){
	int l1=le[id],r1=ri[id];
	if (l>r1 || l1>r){
		return;
	}
	if (l<=l1 && r1<=r){
		lazy[id]=true;
		dat[id]=0;
		add[id]=0;
		return; 
	}
	push_down(id);
	xgqj(l,r,id*2);
	xgqj(l,r,id*2+1);
	dat[id]=dat[id*2]+dat[id*2+1];
}
inline void addit(int l,int r,int id){
	int l1=le[id],r1=ri[id];
	if (l>r1 || l1>r){
		return;
	}
	if (l<=l1 && r1<=r){
		add[id]++;
		dat[id]+=len[id];
		return; 
	}
	push_down(id);
	addit(l,r,id*2);
	addit(l,r,id*2+1);
	dat[id]=dat[id*2]+dat[id*2+1];
}
inline void ddxg(int p,int id){
	int l1=le[id],r1=ri[id];
	if (l1==r1){
		dat[id]++;
		return;
	}
	push_down(id);
	if (p<=ri[id*2]){
		ddxg(p,id*2);
	}
	else{
		ddxg(p,id*2+1);
	}
	dat[id]=dat[id*2]+dat[id*2+1];
}
bool check(int k){
	int pre=0;
	for (int i=0;i<cnt;i++){
		hve[i]=pow(k,ls[i]-pre);
		pre=ls[i];
	}
	memset(dat,0,sizeof(dat));
	memset(lazy,false,sizeof(lazy));
	memset(add,0,sizeof(add));
	int v,j;
	addit(0,a[0],1);
	for (int i=1;i<n;i++){
		if (a[i]>a[i-1]){
			addit(a[i-1]+1,a[i],1);
			continue;
		}
		v=query(a[i],1);
		j=a[i];
		while (v==hve[j]){
			j--;
			if (j==-1){
				return false;
			}
			v=query(j,1);
		}
		if (j+1<=cnt-1){
			xgqj(j+1,cnt-1,1);
		}
		ddxg(j,1);
	}
	return true;
} 
int main(){
	n=read();
	for (int i=0;i<n;i++){
		a[i]=read();
		ls[i]=a[i];
	}
	sort(ls,ls+n);
	int pre=-1;
	for (int i=0;i<n;i++){
		if (pre!=ls[i]){
			pre=ls[i];
			lsh[pre]=cnt;
			ls[cnt++]=ls[i];
		}
	}
	build(0,cnt-1,1);
	for (int i=0;i<n;i++){
		a[i]=lsh[a[i]];
	}
	int mid,l=1,r=2e5+1,ans;
	while (l<=r){
		mid=(l+r)>>1;
		if (check(mid)){
			r=mid-1;
			ans=mid;
		}
		else{
			l=mid+1;
		}
	}
	printf("%d\n",ans);
	return 0;
}
/*
input:
*/
