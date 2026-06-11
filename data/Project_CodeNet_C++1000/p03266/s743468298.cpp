#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
int mod = 1000000000+7;

int main(){

	ll n,k;
	cin>>n>>k;

	ll ans=0;
	ans+=(n/k)*(n/k)*(n/k);
	if(k%2==0){
		ll count=0,i=k/2;
		while(i<=n){
			count++;
			i+=k;
		}
		ans+=count*count*count;
	}
	cout<<ans<<endl;

	return 0;
}
