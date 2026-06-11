#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;

int main(){
	int n;cin>>n;ll a[n],s[n+1]={0};map<ll,ll> num;
	for(int i=0;i<n;i++){
		cin>>a[i];
		s[i+1]=s[i]+a[i];
		if(i==0) num[s[i]]++;
		num[s[i+1]]++;
	}
	ll ans=0;
	for(auto i:num){
		ll sum=i.second;
		ans+=sum*(sum-1)/2;
	}
	cout<<ans<<endl;
}