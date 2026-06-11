#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdio>
#include <cmath>
#include <set>
using namespace std;
const int maxn=1e5+5;
int t1[maxn*4];
inline int lc(int u){
	return u<<1;
}
inline int rc(int u){
	return u<<1|1;
}
inline void co(int u){
	t1[u]=t1[lc(u)]+t1[rc(u)];
}
inline void insert(int u,int l,int r,int id,int d){
	//cout<<"print insert "<<l<<' '<<r<<' '<<id<<endl;
	if (l==r){
		t1[u]+=d;
		return;
	}
	int mid=(l+r)/2;
	if (id<=mid) insert(lc(u),l,mid,id,d);
	else insert(rc(u),mid+1,r,id,d);
	co(u);
}
inline int kth(int u,int l,int r,int k){
	if (l==r) return l;
	int mid=(l+r)/2;
	if (k-t1[lc(u)]>0) return kth(rc(u),mid+1,r,k-t1[lc(u)]);
	else return kth(lc(u),l,mid,k);
}
int a[maxn],num[maxn],len;
int n,k,m;
vector<int> adj[maxn];
int ufs[maxn];
inline int find(int u){
	if (ufs[u]==u) return u;
	else return ufs[u]=find(ufs[u]);
}
multiset<int> st[maxn];
inline void upd(int u,int x){
	if (st[u].size()<k-1){
		st[u].insert(x);
		return;
	}
	else{
		multiset<int>::iterator it1;
		it1=st[u].begin();
		if ((*it1)<x){
			int tp=(*it1);
			//cout<<"print tp x "<<tp<<' '<<x<<endl;
			st[u].erase(it1);
			st[u].insert(x);
			insert(1,1,len,tp,1);
		}
		else{
			insert(1,1,len,x,1);
		}
	}
}
inline void prints(multiset<int> s){
	for (multiset<int>::iterator it2=s.begin();it2!=s.end();it2++){
		cout<<(*it2)<<' ';
	}
	cout<<endl;
}
inline void join(int u,int v){
	if (u==0||v==0) return ;
	int ru=find(u),rv=find(v);
	if (ru==rv) return;
	if (st[ru].size()<st[rv].size()) swap(ru,rv);
	for (multiset<int>::iterator it2=st[rv].begin();it2!=st[rv].end();it2++){
		upd(ru,(*it2));
	}
	st[rv].clear();
	ufs[rv]=ru;
}
inline void add(int id){
	upd(find(id),a[id]);
	int u=id-1,v=id+1;
	if (v==n+1) v=0;
	if (a[u]<a[id]) u=0;
	if (a[v]<a[id]) v=0;
	if (u==0&&v==0) return;
	join(id,u);
	join(id,v);
}
int main(){
	cin>>n>>k>>m;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		num[++len]=a[i];
	}
	if (m==1){
		cout<<"0"<<endl;
		return 0;
	}
	if (k==1){
		sort(a+1,a+n+1);
		int ans=2e9;
		for (int i=1;i+m-1<=n;i++){
			//cout<<"print cur "<<a[i+m-1]<<' '<<a[i]<<endl;
			ans=min(ans,a[i+m-1]-a[i]);
		}
		cout<<ans<<endl;
		return 0;
	}
	sort(num+1,num+len+1);
	len=unique(num+1,num+len+1)-num-1;
	for (int i=1;i<=n;i++){
		int x=lower_bound(num+1,num+len+1,a[i])-num;
		adj[x].push_back(i);
		a[i]=x;
	}
	for (int i=1;i<=n;i++){
		ufs[i]=i;
	}
	int ans=2e9;
	for (int i=len;i>=1;i--){
		for (int j=0;j<adj[i].size();j++){
			int tp=adj[i][j];
			add(tp);
		}
		if(t1[1]>=m) ans=min(ans,num[kth(1,1,len,m)]-num[i]);
	}
	cout<<ans<<endl;
}