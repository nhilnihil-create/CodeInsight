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
void add_self(ll&a , ll b){a=(a+b)%mod;}
//#define (x)  get<0>(x) 
//#define (x)  get<1>(x)
//#define (x)  get<2>(x)
ll query(vector<ll>& bit , ll x){

	ll res = 0 ; 
	while(x>0){
		max_self(res,bit[x]);
		x-=(x&-x);
	}
return res; 

}
void update(vector<ll>& bit , ll x , ll val){

	ll n = bit.size() ; 
	while(x<n){
		max_self(bit[x]  , val);
		x+=(x&-x);
	}
}


signed main(){
ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
ll n ; cin >> n ;
vector<ll> arr (n) ; for(ll i = 0 ; i<n ; i++)cin>> arr[i] ;
vector<ll>bit(n+1) ; 
ll ans = 0  ;
for(ll i = 0;  i< n ; i++){
	ll k ; cin >> k ;
	ll res = query(bit , arr[i] - 1);
	// cout << arr[i] -1 << "  "<< res <<endl;
	max_self(ans , res + k );
	update(bit , arr[i] , k + res);
	// for(auto it : bit)cout <<it<<" " ; cout << endl;

	
}
cout << ans << endl;

	
}