#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
#define ll long long
using namespace std;
const int N=1e5+5;
int n,id[N],fa[N],siz[N]; ll a[N]; map<ll,int> mp;
bool cmp(int x,int y){ return a[x]>a[y]; }
int main(){
	scanf("%d",&n);
	rep (i,1,n){
		scanf("%lld",&a[i]);
		mp[a[i]]=i; id[i]=i; siz[i]=1;
	}
	sort(id+1,id+1+n,cmp);
	//rep(i,1,n) cout<<id[i]<<" ";
	//cout<<endl;
	rep (i,1,n-1){
		int x=id[i];
		fa[x]=mp[a[x]-n+2*siz[x]];
		//cout<<x<<" "<<fa[x]<<endl;
		if (!fa[x]) return puts("-1"),0;
		siz[fa[x]]+=siz[x];
	}
	rep (i,1,n-1) a[id[n]]-=siz[id[i]];
	if (a[id[n]]) return puts("-1"),0;
	rep (i,1,n-1) printf("%d %d\n",id[i],fa[id[i]]);
	return 0;
}
