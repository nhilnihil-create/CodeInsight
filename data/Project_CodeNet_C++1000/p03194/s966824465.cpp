#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

ll n, p;
ll ans = 1, e = 0, q = 0;

vector<ll> prime_factor(ll n){
	vector<ll> res;
	for (ll i = 2; i * i <= n; i++){
		while (n % i == 0){
			res.push_back(i);
			n /= i;
		}
	}
	if (n != 1) res.push_back(n); 
	return res;
}

int main(){
	cin >> n >> p;
	vector<ll> v = prime_factor(p);
	for (int i = 0; i < v.size(); ++i){
		if (q != v[i]) q = v[i], e = 0;
		e++;
		if (e % n == 0) ans *= v[i];
	}
	cout << ans << endl;
}