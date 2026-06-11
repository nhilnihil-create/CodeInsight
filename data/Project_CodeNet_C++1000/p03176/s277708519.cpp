// first second push_back unordered return continue break vector visited check flag bool while iterator begin end lower_bound upper_bound temp true false ll_MAX ll_MIN insert erase clear pop push compare ll64_MAX ll64_MIN  reverse replace stringstream string::npos length substr front
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define all(x) x.begin(),x.end()
const ll mod = 1e9 + 7 ;
const ll inf =
 1e9 + 5 ;
 //1e18L + 5;
const ll nax = 2e5 + 5;
void min_self(ll&a , ll b){a=min(a,b);}
void max_self(ll&a , ll b){a=max(a,b);}
void add_self(ll&a , ll b){a=(a+b);}
//#define (x)  get<0>(x) 
//#define (x)  get<1>(x)
//#define (x)  get<2>(x)
signed main(){
ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
ll n ; cin >> n ;
vector<ll> arr(n) ; for(ll i = 0 ; i<n ; i++)cin>> arr[i] ;
ll base = 1; 
while(base<=2*n)base*=2;
// cout << base << endl;
ll ans = 0 ;
vector<ll>tree(2*base) ;
for(ll i = 0 ; i< n ; i++){
	ll k ; cin >> k ; 
	ll l = 1 + base , r = base + arr[i] - 1 , res = 0;

	while(l<=r){
		if(l%2==1)max_self(res,tree[l++]);
		if(r%2==0)max_self(res,tree[r--]);
		l/=2;r/=2;
	}
	// cout << arr[i] - 1 << " " << res << endl;
	max_self(ans , k + res);
	// tree[base + arr[i]] = k ; 
	ll x = base + arr[i] ;
	while(x>0){
		max_self(tree[x] ,res + k);
		x/=2;
	}

}
cout << ans << endl;

	
}