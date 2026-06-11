#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i,n) for(ll i=0;i<n;i++)

int main(){
	ll n;cin>>n;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=10*n;j++){
			if(4*i*j-j*n-i*n==0) continue;
			if((n*i*j)%(4*i*j-n*j-n*i)==0&&(n*i*j)/(4*i*j-n*j-n*i)>0){
				cout<<i<<" "<<j<<" "<<(n*i*j)/(4*i*j-n*j-n*i)<<"\n";
				return 0;
			}
		}
	}
}