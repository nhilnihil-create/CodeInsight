#include <bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define N 111111
using namespace std;
int n,c,x[N],y[N];
int sum1[N],sum2[N];
int f1[N],f2[N],g1[N],g2[N];
int ans=0;
signed main(){
	cin>>n>>c;
	for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
	for(int i=1;i<=n;i++){
		sum1[i]=sum1[i-1]+y[i];
		f1[i]=max(f1[i-1],sum1[i]-x[i]);
		g1[i]=max(g1[i-1],sum1[i]-x[i]*2);
	}
	for(int i=n;i>0;i--){
		sum2[i]+=sum2[i+1]+y[i];
		f2[i]=max(f2[i+1],sum2[i]-(c-x[i])*2);
		g2[i]=max(g2[i+1],sum2[i]-(c-x[i]));
	}
	rep(i,n+1){
		ans=max(ans,f1[i]+f2[i+1]);
		ans=max(ans,g1[i]+g2[i+1]);
	}
	cout<<ans<<endl;
	return 0;
}

