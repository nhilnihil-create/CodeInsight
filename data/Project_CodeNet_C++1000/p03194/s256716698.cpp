#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <math.h>

using namespace  std;
#define ll unsigned long long int 
#define mp make_pair
#define pb push_back

ll n,p;

bool is_prime(ll n){
	if(n<=1){
		return false;
	}
	if(n<=3){
		return true;
	}
	if(n%2==0 || n%3==0){
		return false;
	}
	for(ll i=5;i*i<=n;i++){
		if(n%i==0 || n%(i+2)==0){
			return false;
		}
	}
	return true;
}
void solve(){
	ll xx=p;
	map<ll,ll> hm;
	for(ll i=2;i*i<=p;i++){
		while(xx%i==0){
			if(hm.count(i)>0){
				hm[i]+=1;
			}
			else{
				hm[i]=1;
			}
			xx=xx/i;
		}
	}
	if(xx!=1){
		if(hm.count(xx)>0){
			hm[xx]+=1;
		}
		else{
			hm[xx]=1;
		}
	}
	ll ans=1;
	for(auto i : hm){
		if(i.second<n){
			continue;
		}
		else{
			ans=ans*pow(i.first,(i.second/n));
		}
	}
	printf("%lld\n",ans);
}
int main(){
	// ll n,p;
	scanf("%lld%lld",&n,&p);
	if(is_prime(p)){
		printf("1\n");
	}
	else{
		solve();
	}
	return 0;
}