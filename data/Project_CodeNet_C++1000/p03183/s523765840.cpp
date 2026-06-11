#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct node{
	int w,s;
	ll v;
}a[30005];
int n; 
ll f[30005],ans;
bool cmp(node a,node b){
	return a.w+a.s<b.w+b.s;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i].w>>a[i].s>>a[i].v;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;++i){
		for(int j=a[i].s;j>=0;--j){
			f[j+a[i].w]=max(f[j+a[i].w],f[j]+a[i].v);
		}
	}
	for(int i=0;i<30005;++i){
		ans=max(ans,f[i]);
	}
	cout<<ans<<'\n';
	return 0;
}