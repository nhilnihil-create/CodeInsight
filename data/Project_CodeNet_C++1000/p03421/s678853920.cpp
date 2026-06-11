#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main(){
	ios_base::sync_with_stdio(false);
	ll n, a, b;
	cin >> n >> a >> b;
	if(n == 1){
		if(a == 1 && b == 1){
			cout << 1 << endl;
		}else{
			cout << -1 << endl;
		}
		return 0;
	}
	if(a + b - 1 > n){
		cout << -1 << endl;
		return 0;
	}
	if(n > a * b){
		cout << -1 << endl;
		return 0;
	}
	ll last = 0;
	for(ll i = 0; i < a; ++i){
		const ll length = min(b, (n - last) - (a - i - 1));
		for(ll j = 0; j < length; ++j){
			cout << last + length - j << " ";
		}
		last += length;
	}
	cout << endl;
	return 0;
}

