#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main(){
	IOS;
	int a, b;
	cin >> a >> b;
	if( a < 9 && b < 9 ){
		cout << "Yay!\n";
	}else{
		cout << ":(\n";
	}
	return 0;
}