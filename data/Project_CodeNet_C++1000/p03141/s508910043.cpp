#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[114514],b[114514],c[114514];
int main(){
	ll n;
	cin>>n;
	ll ans=0;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		c[i]=a[i]+b[i];
		ans-=b[i];
	}
	sort(c,c+n);
	for(int i=n-1;i>=0;i-=2)ans+=c[i];
	cout<<ans<<endl;
	return 0;
}
