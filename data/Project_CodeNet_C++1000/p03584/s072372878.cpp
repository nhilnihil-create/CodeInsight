#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

int main(void){
	ll n,k;
	vector<ll>a,b;
	cin >> n >> k;
	a.resize(n); b.resize(n);
	ll ans = 0;
	for(int i = 0; i < n; ++i){
		cin >> a[i] >> b[i];
		if((a[i]|k) <= k)
			//cout << (a[i]|k)  << endl;
			ans += b[i];
	}
	ll cnt = 0;
	ll tmp = k;
	while(true){
		if(tmp == 0) break;
		tmp /= 2;
		cnt++;
	}
	for(int i = cnt; i >= 0; --i){
		//cout << (k&(1<<i)) << endl;
		if((k & (1<<i))){
			//cout << i << endl;
			ll bit = (1<<i) - 1;
			bit = (bit|k) - (1<<i);
			//cout << bit << endl;
			ll tmp = 0;
			for(int j = 0; j < n; ++j){
				if((bit|a[j]) <= bit){
					tmp += b[j];
				}
			}
			if(ans < tmp){
				ans = tmp;
			}
		}
	}
	cout << ans << endl;
	return 0;
}