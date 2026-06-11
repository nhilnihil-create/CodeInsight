#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
int main(){
	double n; cin >> n;
	double k; cin >> k;
	double ans = 0;
	for(ll i = 1; i <= n; ++i){
		ll cnt = 0, tmp = i;
		while(tmp < k){
			tmp *= 2;
			cnt++;
		}
		ans += (double(1) / double(n)) * double(pow((double(1)/ double(2)), double(cnt)));
	}
	cout << setprecision(12) << ans;
	cout << fixed;
    return 0;
}
