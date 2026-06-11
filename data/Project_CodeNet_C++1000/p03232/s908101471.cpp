#include <bits/stdc++.h>
typedef long long ll;
#define  rep(i,a,b)for(long long i=a;i<b;++i)
#define  rrep(i,a,b)for(int i=a;i>=b;--i)
#define  yesno(flag)if(flag)cout<<"Yes"<<endl; else cout<<"No"<<endl;
using namespace std;
const int INF=1000000000LL;
const ll r197=1000000007;
typedef pair<int,int>P;
typedef pair<int,P>Pa;
ll b[100005]={},d1[100005],d2[100005];

int main() {
	ll n,a[100002];
	cin>>n;
	rep(i,0,n){
		cin>>a[i];
	}
//	ll c=1;
	d1[0]=1;
	d2[n+1]=1;
	rep(i,1,n+1){
		d1[i]=(i*d1[i-1])%r197;
	}
	rrep(i,n,1){
		d2[i]=(i*d2[i+1])%r197;
	}
	rep(i,1,n+1){
		b[i]=(d1[i-1]*d2[i+1])%r197;
		b[i]=(b[i]+b[i-1])%r197;
	}
	ll ans=0;
	rep(i,0,n){
		ll s=b[i+1]+b[n-i]-b[1];
		if(s<0)s+=r197;
		ll v=(s*a[i])%r197;
		ans=(ans+v)%r197;
	}
	cout<<ans<<endl;
	return 0;
}
