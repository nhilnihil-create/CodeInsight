#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
int main(){
	ll n,ans=0;
	cin>>n;
	for(ll i=1;i*i<=n;i++){
		if((n-i)%i==0&&(n-i)/i>i){
			ans+=(n-i)/i;
		}
	}
	cout<<ans<<endl;
}