#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main(){
	IOS;
	int n;
	cin >> n;
	int a, ans = 0;
	while( n-- ){
		cin >> a;
		while(a%2 == 0 && a > 0 )
			a = a/2, ans++;
	}

	cout << ans << endl;
	return 0;
}