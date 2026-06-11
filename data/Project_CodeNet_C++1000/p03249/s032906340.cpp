#include<bits/stdc++.h>
using namespace std;
const int N=100005;
typedef long long ll;
int sz[N],i,n,rsz[N],a[N],x,y,fa[N];
ll z,d[N];
multiset<pair<ll,int> >s[2];
inline void ins(int u){
	if(rsz[u]==1)return;
	s[(n+d[u])&1].insert(make_pair(n+d[u]-rsz[u]*2,u));
}
bool cmp(const int&x,const int&y){return d[x]<d[y];}
inline void O(){cout<<"-1\n";exit(0);}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(i=1;i<=n;++i)cin>>d[i],a[i]=i;
	sort(a+1,a+n+1,cmp);sz[a[1]]=rsz[a[1]]=n;ins(a[1]);
	for(i=2;i<=n;++i){
		x=a[i];
		multiset<pair<ll,int> >::iterator it=s[d[x]&1].upper_bound(make_pair(d[x],0));
		if(it==s[d[x]&1].begin())O();--it;y=it->second;
		z+=rsz[x]=sz[x]=(n+d[y]-d[x])/2;rsz[y]-=sz[x];
		s[d[x]&1].erase(it);ins(y);ins(x);fa[x]=y;
	}
	if(z!=d[a[1]])O();
	for(i=1;i<=n;++i)if(fa[i])cout<<fa[i]<<' '<<i<<'\n';
	return 0;
}