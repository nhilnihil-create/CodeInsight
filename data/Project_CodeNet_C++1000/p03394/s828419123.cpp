#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef pair<ll, ll>P;
ll gcd(ll x, ll y) {
	if (y == 0)return x;
	return gcd(y, x % y);
}
ll lcm(ll x, ll y) {
	return x * y / gcd(x, y);
}
ll basic[33333];
signed main(){
	ll n,memo=0,ans=0;
	cin>>n;
	for(int i=1;i<=33333;i++){
		if(i%2==0||i%3==0){
			basic[memo]=i;
			memo++;
		}
	}
	rep(i,n-1){
		cout<<basic[i]<<" ";
		ans+=basic[i];
	}
	ll p=0;
	for(int i=2;i<=30000;i++){
		if((i%3==(3-(ans%3))%3)&&(i%2==(2-(ans%2))%2)&&(gcd(i,ans)!=1)){
			for(int j=0;j<n-1;j++){
				if(i==basic[j])p++;
			}
			if(p==0){
				cout<<i;
				return 0;
			}
		}
		p=0;
	}
}
