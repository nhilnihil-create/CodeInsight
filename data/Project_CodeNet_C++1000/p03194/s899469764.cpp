#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> p;
const int inf=(1<<30);
#define rep(i,a,n)	for(int i=a;i<n;i++)
#define rrep(i,a,n) for(int i=(a-1);i>=n;i--)

int main(){
	ll n,p;
	cin>>n>>p;
	if(n==1){
		cout<<p<<endl;
		return 0;
	}
	vector<ll> v;
	for(ll i=2;i*i<=p;i++){
		bool sosuu=true;
		for(ll j=2;j*j<=i;j++){
			if(i%j==0){
				sosuu=false;
				break;
			}
		}
		if(sosuu==false)continue;
		else{
			ll cnt=0;
		while(p%i==0){
				p/=i;
				cnt++;
			}
			if(cnt>=n){
				ll x=cnt/n;
				rep(k,0,x)v.push_back(i);
			}
		}
	}
	ll ans=1;
	rep(i,0,v.size()){
		ans*=v[i];
	}
	cout<<ans<<endl;
}