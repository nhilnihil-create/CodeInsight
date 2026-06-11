#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll n,h,w,ans=0;
	cin>>n>>h>>w;
	while(n--){
		ll x,y;
		scanf("%lld %lld",&x,&y);
		ans=x>=h&&y>=w?ans+1:ans; 
	} 
	cout<<ans<<endl;
} 