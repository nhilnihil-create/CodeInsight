#include<bits/stdc++.h>

#define I inline void 

using namespace std ; 

using ld = long double ; 
using ll = long long ; 

const int N = 1e6  + 7 , mod = 1e9 + 7 ; 

int n;   

ll a[N] ; 

ll bit[N] ; 
ll num[N]; 

I add(ll i , ll x){
	for(;i<N;i+=i&-i)
		bit[i]+=x ;
}

ll upto(ll x){
	ll ret = 0 ; 
	for(;x;x-=x&-x)
		ret+=bit[x] ; 
	return ret ; 
}

ll check(ll x){
	memset(bit , 0 , sizeof bit) ; 
	ll ret = 0 ; 
	ll aux[N] ; 
	for(int i = 0 ; i < n ;i++){
		if(a[i] >= x)aux[i] =1 ; 
		else aux[i] = -1 ; 
	}
	for(int i = 1;i < n ;i++)
		aux[i]+=aux[i-1]; 
	add( 200000  , 1) ; 
	for(int i = 0 ;i < n;i++){
		ret+=upto(aux[i] + 200000 ) ; 
		add(aux[i] + 200000  , 1) ; 
	}
	return ret ;
}

int main(){
	ios_base::sync_with_stdio(0) ; 
	cin.tie(0) ; 
	//freopen("in.in"  ,"r" , stdin) ; 

	cin >> n ; 

	std::vector<pair<int , int > > v;

	for(int i = 0 ;i < n;i++){
		int x ; 
		cin >> x ; 
		v.push_back({x , i}) ; 
	}
	sort(v.begin() , v.end()) ;
	a[v[0].second] = 1;  
	for(int i = 1 ;i < n;i++)
		a[v[i].second] = a[v[i-1].second] + (v[i].first > v[i-1].first) ; 

	ll lo = 1 , hi = n; 
	ll ans = v[n-1].first ; 
	ll m = 1ll * n * (n + 1) / 2ll  ; 

	m = (m + 1ll) / 2ll ;

	for(int i = 0 ; i< n;i++){
		num[ a[v[i].second] ] = v[i].first ;
	}

	while(lo<=hi){
		ll mid = (lo + hi) >> 1; 
		if(check(mid) >= m){
			lo = mid +1 ; 
			ans = mid ; 
		}
		else {
			hi = mid -1 ;
		}
	}
	cout<< num[ans] ; 
	return 0 ; 
}