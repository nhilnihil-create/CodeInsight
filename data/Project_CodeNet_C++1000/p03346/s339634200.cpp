#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef vector<ll> vi;
int main(){
    ios_base::sync_with_stdio(false);
	ll n;cin>>n;
	vi v(n);
	for(ll i=0;i<n;i++){
		ll a;cin>>a;
		v[a-1]=i;
	}
	ll ans=1,cnt=1;
	for(ll i=0;i<n-1;i++){
		if(v[i]<v[i+1])
			cnt++;
		else
			cnt=1;
		ans=max(cnt,ans);
	}
	cout<<n-ans<<endl;
	return 0;
}

