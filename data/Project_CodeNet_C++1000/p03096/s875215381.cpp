#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
int a[200010],b[200010];
int f[200010],g[200010];
int n,m;
int main(){
	cin>>n;
	rep(i,1,n)cin>>a[i];
	rep(i,1,n)if(i==0||a[i]!=a[i-1])m++,b[m]=a[i];
	n=m;
	rep(i,1,n)a[i]=b[i];
	f[0]=1LL,g[a[1]]=1LL;
	rep(i,1,n)f[i]=g[a[i]],g[a[i+1]]=(g[a[i+1]]+f[i])%1000000007;
	cout<<f[n]<<endl;
	return 0;
}
