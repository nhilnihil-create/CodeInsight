#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){

	ios::sync_with_stdio(false);

	int a, b, ans;
	cin >> a >> b;
	
	if (a >12) ans =b;
	else if (a<=5) ans = 0;
	else ans = b/2;
	
	cout << ans << "\n";
	return 0;
}