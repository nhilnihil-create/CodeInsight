#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n;
ll a[100005];
ll modpow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
ll F[100005],R[100005],rui[100005];
void make(){
	F[0] = 1;
	for(int i=1;i<100005;i++) F[i] = F[i-1]*i%mod;
	for(int i=1;i<100005;i++) R[i] = modpow(i,mod-2);
	for(int i=1;i<100005;i++) rui[i] = (rui[i-1]+R[i])%mod;
}
int main(){
	cin>>n;
	make();
	ll ans = 0;
	repn(i,n){
		cin>>a[i];
		ll coef = rui[i]+rui[n-i+1];
		coef = (coef%mod+mod-1)%mod;
		ans += coef*a[i]%mod;
		//cout << coef << endl;
		ans %= mod;
	}
	cout << ans*F[n]%mod << endl;
}