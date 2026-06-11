#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int n,c;cin>>n>>c;
	vector<int> x(n+1,0),v(n+1,0),s(n+1,0),a(n+1,0),b(n+1,0);
	for(int i=1;i<=n;i++){
	cin>>x[i]>>v[i];
	s[i]=s[i-1]+v[i];
	a[i]=max(a[i-1],s[i]-2*x[i]);
	b[i]=max(b[i-1],s[i]-x[i]);
	}
	int ans=b[n];
	int a0=0,b0=0;
	for(int i=n;i>0;i--){
		a0=max(a0,s[n]-s[i-1]-2*(c-x[i]));
		b0=max(b0,s[n]-s[i-1]-(c-x[i]));
		ans=max({ans,a[i-1]+b0,b[i-1]+a0});
	}
	cout<<ans<<endl;

}
