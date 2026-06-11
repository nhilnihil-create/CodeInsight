#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i,n) for(ll i=0;i<n;i++)

int main(){
	int n;cin>>n;
	ll c[n-1],s[n-1],f[n-1];
	rep(i,n-1) cin>>c[i]>>s[i]>>f[i];

	ll ans[n-1]={};
	for(int i=0;i<n-1;i++){
		ll T=s[i]+c[i];
		for(int j=i+1;j<n-1;j++){
			if(T<s[j]) T=s[j];
			else if(T%f[j]!=0) T+=f[j]-T%f[j];
			T+=c[j];
		}
		ans[i]=T;
	}

	rep(i,n-1) cout<<ans[i]<<"\n";
	cout<<0<<"\n";
}