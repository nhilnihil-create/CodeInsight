#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[100010],p=1,ans,x,mo=1000000007;
ll po(ll x,ll y){ll z=1;while (y){if (y%2==1)z=(x*z)%mo;x=(x*x)%mo;y/=2;}return z;}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)a[i]=(a[i-1]+po(i,mo-2))%mo;
	for (int i=1;i<=n;i++){p=p*i%mo;cin>>x;ans=(ans+x*(a[i]+a[n-i+1]-1))%mo;}
	cout<<ans*p%mo;
	return 0;
}