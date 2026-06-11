#include<bits/stdc++.h>
#define ll long long
#define int long long
#define ljc 998244353
using namespace std;
#define gc getchar
inline ll read(){
    register ll x=0,f=1;char ch=gc();
    while (!isdigit(ch)){if (ch=='-') f=-1;ch=gc();}
    while (isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0';ch=gc();}
    return (f==1)?x:-x;
}
int n;
struct node{
	ll x;
	int id;
}x[1010101];
inline bool cmp(node a,node b){
	return a.x>b.x;
}
int sz[1010101],ans[1010101];
map<ll,int> mp;
vector<pair<int,int> > as;
signed main(){
	n=read();
	for (int i=1;i<=n;i++) x[i].x=read(),x[i].id=i,sz[i]=1,mp[x[i].x]=i;
	sort(x+1,x+1+n,cmp);
	if (n==1){
		puts(x[1].x==0?"":"-1");
		return 0;
	}
	if (n==2){
		puts("-1");
		return 0;
	}
	for (int i=1;i<n;i++){
		if (!mp.count(x[i].x-n+sz[x[i].id]+sz[x[i].id])){
			puts("-1");
			return 0;
		}
		int faa=mp[x[i].x-n+sz[x[i].id]+sz[x[i].id]];
		as.push_back(make_pair(faa,x[i].id));
		sz[faa]+=sz[x[i].id];
		ans[faa]+=ans[x[i].id]+sz[x[i].id];
	}
	if (ans[x[n].id]!=x[n].x){
		puts("-1");return 0;
	}
	for (auto i:as) printf("%d %d\n",i.first,i.second);
    return 0;
}
