#include <bits/stdc++.h>
using namespace std;
const int N = 0x3f3f3f3f;
int ans , n , m , mivn = N;
int main(){
	cin >> n >> m;
	ans = 0 ;
	for (int i=1;i<=n;i++){
		int x;
		cin >> x;
		ans ++;
		m -= x; 
		mivn = min(x,mivn);
	}
	while ( m >= mivn ){
		ans ++ ;
		m -= mivn;
	}
	cout<<ans<<endl;
	return 0;
}