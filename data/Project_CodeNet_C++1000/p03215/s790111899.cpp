#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll a[1002],seki[41];
int main() {
	ll n,k;
	cin>>n>>k;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	seki[0]=1;
	for(ll i=1;i<=40;i++){
		seki[i]=2*seki[i-1];
	}
	vector<ll>b;
	for(ll i=0;i<n;i++){
		ll sum=0;
		for(ll j=0;j+i<n;j++){
			sum+=a[i+j];
			b.push_back(sum);
			//cout <<sum<<endl;
		}
	}
	ll ans=0;
	for(ll i=40;i>=0;i--){
		ll cnt=0;
		for(ll j=0;j<b.size();j++){
			if((ans+seki[i]&b[j])==ans+seki[i]){
				cnt++;
			}
		}
		if(cnt>=k){
			ans+=seki[i];
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}