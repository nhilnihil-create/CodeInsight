#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 

int main() {
	ll n,m;
	cin>>n>>m;
	map<ll,ll>a;
	for(ll i=0;i<n;i++){
		ll x;
		cin>>x;
		x=-x;
		a[x]++;
	}
	for(ll i=0;i<m;i++){
		ll b,c;
		cin>>b>>c;
		a[-c]+=b;
	}
	ll ans=0;
	ll cnt=0;
	for(auto itr=a.begin();itr!=a.end();itr++){
		ll num=itr->first;
		ll val=itr->second;
		cnt+=val;
		ans+=num*val;
		if(cnt>=n){
			ans-=(cnt-n)*num;
			break;
		}
	}
	cout << abs(ans);
	// your code goes here
	return 0;
}