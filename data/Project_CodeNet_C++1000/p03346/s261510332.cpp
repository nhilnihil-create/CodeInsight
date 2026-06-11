#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	ll a[200010];
	for(ll i=0;i<n;i++){
		ll x;
		cin>>x;
		x--;
		a[x]=i;
	}
	ll cnt=1;
	ll ans=1;
	for(ll i=1;i<n;i++){
		if(a[i-1]<a[i]){
			cnt++;
			ans=max(ans,cnt);
		}
		else{
			cnt=1;
		}
	}
	cout << n-ans;
	// your code goes here
	return 0;
}