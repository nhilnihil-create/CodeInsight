#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> piii; 
#define fi first
#define se second 
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(ll x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int n;
piii v[1003];
bool cmp(piii a,piii b){
	return a.fi.fi+a.fi.se>b.fi.fi+b.fi.se;
}
ll dp[10003],ans;
int main(){
	read(n);
	for (int i=1;i<=n;i++) read(v[i].fi.fi),read(v[i].fi.se),read(v[i].se);
	sort (v+1,v+1+n,cmp);
	for (int i=1;i<=n;i++){
		for (int j=0;j<=10000;j++)
			if (j>=v[i].fi.fi) dp[min(j-v[i].fi.fi,v[i].fi.se)]=max(dp[min(j-v[i].fi.fi,v[i].fi.se)],dp[j]+v[i].se);
		dp[v[i].fi.se]=max(dp[v[i].fi.se],1ll*v[i].se);
	}
	for (int i=0;i<=10000;i++) ans=max(ans,dp[i]);
	write(ans);
}