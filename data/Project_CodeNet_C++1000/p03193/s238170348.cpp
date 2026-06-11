#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans=0,h,w,a,b;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>h>>w;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		if(a>=h&&b>=w) ans++;
	} 
	cout<<ans;
	return 0;
}