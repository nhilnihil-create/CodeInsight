#include<bits/stdc++.h>
using namespace std;
#define ll long long
void max_self(ll&a , ll b){a=max(a,b);}
signed main(){
ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
ll n ; cin >> n ;
vector<ll> arr (n) ,bit(n+1) ; 
for(ll i = 0 ; i<n ; i++)cin>> arr[i] ;
ll ans = 0  ;
for(ll i = 0;  i< n ; i++){
	ll k ; cin >> k ;
	ll res = 0 ;
	ll x = arr[i] - 1 ; 
	while(x>0){
		max_self(res , bit[x]) ; 
		x-=(x&-x);
	}
	max_self(ans , res + k );
	x = arr[i] ; 
	while(x < bit.size()){
		max_self(bit[x] , res +  k);
		x+=(x&-x);
	}	
}
cout << ans << endl;	
}