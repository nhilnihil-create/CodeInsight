#include <bits/stdc++.h>

using namespace std;

int main(){

	int a,b,c,k;

	cin >> a >> b >> c >> k;

	int ans = a+b+c;
	int mx = max({a,b,c});

	while(k--){
		ans+=mx;
		mx*=2;
	}

	cout << ans << '\n';

return 0;
}