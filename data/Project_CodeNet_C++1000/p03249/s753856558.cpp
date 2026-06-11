#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<typename tn> void read(tn &a){
	tn x=0,f=1; char c=' ';
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	a=x*f;
}
int n,p[101000],s[101000],vis[101000];
ll a[101000];
vector<pair<int,int> > ans;
map<ll,int> mp;
int main(){
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);mp[a[i]]=i;
		p[i]=i;s[i]=1;
	}
	sort(p+1,p+n+1,[&](int x,int y){
		return a[x]>a[y];
	});
	ll res=0;
	for(int i=1;i<n;i++){
		int x=p[i];
		mp.erase(a[x]);
		ll pos=a[x]+s[x]-(n-s[x]);
		if(!mp.count(pos)){puts("-1");return 0;}
		ans.emplace_back(x,mp[pos]);
		s[mp[pos]]+=s[x];res+=s[x];
	}
	if(a[p[n]]!=res){puts("-1");return 0;}
	for(auto pr:ans){
		cout<<pr.first<<' '<<pr.second<<'\n';
	}
	return 0;
}
