#include <iostream>
#include <vector>
using namespace std ;
using ll = long long ;

int main(){
	ll n ; cin >> n ;
	vector<ll> a(n),b(n) ;
	for(auto &i:a) cin >> i ;
	for(auto &i:b) cin >> i ;
	ll cnt = 0 ;
	for(int i=0;i<n;i++){
		if(a.at(i)>=b.at(i)) cnt -= a.at(i)-b.at(i) ;
		else cnt += (b.at(i)-a.at(i))/2 ;
	}
	cout << (cnt>=0?"Yes":"No") << endl ;
}
