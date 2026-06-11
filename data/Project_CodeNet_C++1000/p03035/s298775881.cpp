#include <bits/stdc++.h>
using namespace std;
using lint = long long;

signed main(){
	int a, b, ans; cin >> a >> b;
	if(a >= 13) ans = b;
	else if(6 <= a) ans = b / 2;
	else ans = 0;
	cout << ans << endl;
}