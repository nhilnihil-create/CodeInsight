#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
int main(){
	ll k, a, b;
	cin >> k >> a >> b;
	if(b - a <= 2){
		cout << k + 1;
		return 0;
	}
	else if(a - 1 >= k){
		cout << k + 1 << endl;
	}else{
		ll rest = k - (a - 1);
		ll ans = a;
		ans += (rest / 2) * (b - a);
		if(rest % 2 == 1)ans++;
		cout << ans;
	}
	
    return 0;
}
