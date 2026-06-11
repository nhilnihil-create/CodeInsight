/*I - Poisonous Cookies*/

#include <bits/stdc++.h>
using namespace std;

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b, c;

	int ans = 0;

	cin >> a >> b >> c;

	if( c <= a){
		ans += c;
		ans += b; 
	}
	else{
		
		ans = a;
		c-= a;

		if(c <= b){
			ans += c + b;
		}
		else{
			ans += (b * 2);
			c -= b;

			if (c > 0)
				ans++;
		}
	}

	cout << ans;

	return 0;
}