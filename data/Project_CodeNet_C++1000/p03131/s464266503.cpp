#include <iostream>
#include <algorithm>
using namespace std ;
using ll = long long ;

int main(){
	ll k,a,b ;
	cin >> k >> a >> b ;
	k++ ;
	ll ans = k ;
	if(a<b){
		if(a+2<=k) ans = max(ans,b+(k-a-2)/2*(b-a)+(k-a-2)%2) ;
	}
	cout << ans << endl ;
}
