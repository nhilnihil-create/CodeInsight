#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

int main(){
	int x, y;
	ll ans;
	cin >> x >> y;
	if(x % y == 0){
		cout << -1 << endl;
		return 0;
	}
	for(ll i = 1;;i++){
		ans = (ll)x * i;
		if(y % ans != 0){
			cout << ans << endl;
			return 0;
		}
	}
}