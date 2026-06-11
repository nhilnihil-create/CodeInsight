#include<bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> divisor(ll n){
    std::vector<ll> res;
    for(ll i = 1LL; i * i <= n; i++){
        if(n % i == 0){
            res.push_back(i);
            ll j = n / i;
            if(i != j)res.push_back(j);
        }
    }
    std::sort(res.begin(),res.end());
    return res;
}

int main()
{
	ll n; cin >> n;
	vector<ll> div = divisor(n);
	ll sum = 0;
	for(auto i : div) {
		ll m = i - 1;
		if(m == 0)continue;
		if(n % m == n / m) sum += m;
	}
	cout << sum << endl;
}