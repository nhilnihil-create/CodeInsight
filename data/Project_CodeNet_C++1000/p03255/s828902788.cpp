#include<bits/stdc++.h>
#define reg register
using namespace std;
const int MN=2e5+5;
typedef __int128 ll;
int n,X;
long long a[MN];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cin>>n>>X;
	for(reg int i=1;i<=n;i++)cin>>a[i],a[i]+=a[i-1];
	ll ans=1e18,s;
	for(reg int i=1,j;i<=n;i++){
		s=2*(a[n]-a[n-i])+1ll*(n+i)*X;
		for(j=1;i*j<=n;j++)
			s+=(ll)(2*j+1)*(a[n-i*j+i]-a[n-i*j]);
		s+=(ll)(2*j+1)*a[n-i*j+i];
		ans=min(ans,s);
	}
	cout<<(long long)ans<<endl;
	return 0;
}