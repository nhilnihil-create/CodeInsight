#include <bits/stdc++.h>
using namespace std;
struct nmd{
	long long w,s,v;
}a[1010];
long long dp[20000010],g;
int n;
bool cmp(nmd a,nmd b){
	return (a.w+a.s)<(b.w+b.s);
}
int main(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i].w>>a[i].s>>a[i].v;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;++i){
		for(int j=a[i].s;j>=0;--j){
			dp[j+a[i].w]=max(dp[j+a[i].w],dp[j]+a[i].v);
			//g=max(dp[j],g);
		}
	}
	for(int i=0;i<=20000010;++i){
		g=max(g,dp[i]);
	}
	cout<<g<<endl;
	return 0;
}
