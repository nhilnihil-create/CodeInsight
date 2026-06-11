/*-- ILSH  --*/
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef double ld;
#define pb push_back 
#define pop pop_back
#define mp make_pair
#define vii vector < ll >
#define vll vector < ll > 
#define dt cout<<"HERE\n";
#define pii pair < ll , ll >
#define pll pair < ll , ll >
#define vpi vector < pii >
#define vpl vector < pll >
#define fi first
#define se second 
#define sz size 
#define len length 
const ll inf=1e18+1e17;
const ll mod =1e9+7;
using cd= complex < double > ;
//const ll mod = 998244353;
ll modInverse(ll a,ll m){ll m0=m;ll y=0,x=1;if(m == 1)return 0;while(a> 1){ll q=a/m;ll t=m;m=a%m,a=t;t=y;y=x-q*y;x=t;}if(x<0)x+=m0;return x;}  
ll powm(ll a,ll b){a=a%mod;ll res=1;while(b){if(b&1)res=(res*a)%mod;a=(a*a)%mod;b>>=1;}return (res%mod);}
const ll N = 2e5+5;
ll arr[N];
ll n;
ll find(ll x){
	ll val=0;
	for ( ll i=0;i<n;i++)
		val+=abs( arr[i]-x);
	return val;
}
void solve(){
	cin>>n;
	for ( ll i=0;i<n;i++){
		cin>>arr[i];
		arr[i]-=(i+1);
	}
	ll x=*min_element( arr,arr+n);
	ll y=*max_element( arr,arr+n);
	while ( x<y){
		ll mid=( y-x)/3;
		ll c=x+mid;
		ll d=x+2*mid;
		ll j=find ( c);
		ll k=find ( d);
		if ( j<k)
			y=d;
		else
		if ( j>k)
			x=c;
		else{
			x=c;y=d;
		}
		if ( y-x<=3){
			ll p=x;
			ll val=find( p);
			for ( ll i=x;i<=y;i++){
				ll kal=find( i);
				if ( kal<val){
					val=kal;
					p=i;
				}
			}
			x=p;
			y=p;
		}
	}
	cout<<find(y)<<'\n';
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie( NULL);
	cout.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen ("INPUT.txt" , "r" , stdin);
		freopen ("OUTPUT.txt", "w" , stdout);
	#endif
	ll t=1;
	//cin>>t;
	for ( ll i=1;i<=t;i++){
		//cout<<"Case #"<<i<<": ";
    	solve();
    }
}
