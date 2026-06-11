#include <bits/stdc++.h>
#define int long long
#define inf (int)(3e18)
#define mod (int)(1e9+7)
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n,c;
int x[114514],v[114514];
int sumle1[114514],sumle2[114514];
int sumri1[114514],sumri2[114514];
signed main(){
	cin>>n>>c;
	for(int i=1;i<=n;i++)cin>>x[i]>>v[i];
	{
		int sum=0;
		for(int i=1;i<=n;i++){
			sumle1[i]=sumle1[i-1];
			sumle2[i]=sumle2[i-1];
			sum+=v[i];
			sumle1[i]=max(sumle1[i],sum-x[i]);
			sumle2[i]=max(sumle2[i],sum-x[i]*2);
		}
	}
	{
		int sum=0;
		for(int i=n;i>=1;i--){
			sumri1[i]=sumri1[i+1];
			sumri2[i]=sumri2[i+1];
			sum+=v[i];
			sumri1[i]=max(sumri1[i],sum-(c-x[i]));
			sumri2[i]=max(sumri2[i],sum-(c-x[i])*2);
		}
	}
	int ans=0;
	rep(i,n+1){
		ans=max(ans,sumle1[i]+sumri2[i+1]);
		ans=max(ans,sumle2[i]+sumri1[i+1]);
	}
	cout<<ans<<endl;
}
