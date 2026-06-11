#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

LL ans, sum, xorr ;
deque<LL> ar ;

void update(int n){
	while(true){
		if((sum + n) == (xorr ^ n))
			break ;
		sum -= ar.front() ;
		xorr ^= ar.front() ;
		ar.pop_front() ;
	}

	sum += n ;
	xorr ^= n ;
	ar.push_back(n) ;
	ans += (LL)ar.size() ;
}

int main(){

	LL n, a ;
	cin >> n ;

	while(n--){
		cin >> a ;
		update(a) ;
	}

	cout << ans << endl ;

	return 0;
}