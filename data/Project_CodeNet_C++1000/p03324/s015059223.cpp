#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main(){
	IOS;
	int d, n;
	cin >> d >> n;
	int bs = 1;
	while( d ){
		bs = bs*100;
		d--;
	}
	
	if( n == 100 ){
		bs = bs*101;
	}else{
		bs = bs*n;
	}

	cout << bs << endl;
	return 0;
}