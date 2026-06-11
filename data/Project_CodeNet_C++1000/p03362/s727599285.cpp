#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1e9+7;
#define rep(i,N) for(ll i=0; i<(N); i++)
#define rep1(i,N) for(ll i=1; i<(N); i++)

ll prime[1000005];
bool is_prime[1000005];
ll sieve(ll n){
	ll p=0;
	for(ll i=0; i<=n; i++) is_prime[i]=true;
	is_prime[0]=is_prime[1]=false;
	for(ll i=2; i<=n; i++){
		if(is_prime[i]){
			prime[p++]=i;
			for(ll j=2*i; j<=n; j+=i) is_prime[j]=false;
		}
	}
	return p;
}
ll N;
ll a[60];

int main(){

cin.tie(0);
ios::sync_with_stdio(false);

cin>>N;

ll n=sieve(55555);
ll index=0;
rep(i,n){
	if(prime[i]%5==1){
		a[index]=prime[i];
		index++;
		if(index==N) break;
	}
}

rep(i,N){
	if(i==N-1){
		cout<<a[i]<<endl;
	}else{
		cout<<a[i]<<" ";
	}
}

}
	
