#include<bits/stdc++.h>
using namespace std ; 
# define pb push_back
# define ll long long
# define mp make_pair 
# define endl "\n"
# define vi vector<int>
# define vc vector<char>
# define vll vector<ll> 
# define pi pair<int,int> 
const int MOD = 1e9 + 7 ; 
const ll inf = 1e18 ; 


int main() {
	int n ;
	cin >> n ; 
	vc a(n) ; 
	vi cnt1(n+1) ;
	vi cnt2(n+1) ;  
	for(int i = 0 ; i < n ; ++i){
		cin >> a[i] ; 
	}
	for(int i = 0 ; i < n ; ++i) {
		if(a[i] == '.')
			cnt1[i+1] = 1; 
		else 
			cnt2[i+1] = 1 ; 
	}
	for(int i = 1 ; i <= n ; ++i) {
		cnt1[i] += cnt1[i-1] ; 
		cnt2[i] += cnt2[i-1] ; 
	}
	int ans = n ; 
	for(int i = 0 ; i <=  n ; ++i) {
		//cout << cnt2[i] << " " << cnt1[i] << endl ; 
		ans = min(ans , cnt2[i] + cnt1[n] -  cnt1[i]) ;  
	}
	cout << ans ; 

	return 0; 
}
