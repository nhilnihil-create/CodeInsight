#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ll n,h,w;
	cin>>n>>h>>w;
	vector<ll>a(n),b(n);
	ll ans=0;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		ans+=min(a[i]/h,b[i]/w);
	}
	cout<<ans<<endl;
	return 0;
}