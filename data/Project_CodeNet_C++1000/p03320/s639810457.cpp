#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int maxn = 300 + 10;

int s(ll p){
	int ret = 0;
	while (p){
		ret += p % 10;
		p /= 10;
	}
	return ret;
}

ll f(ll p){
	vector<ll> cnd;
	cnd.push_back(p);
	ll tmp = p;
	ll q = 0, pw = 1;
	while (tmp){
		while (tmp % 10 < 9){
			tmp ++;
			cnd.push_back(pw * tmp + q);
		}
		pw = 10ll * pw;
		tmp /= 10;
		q = 10ll * q + 9;
	}
	int r = cnd.size();
	for (int i = 0; i < r; i++){
		bool bad = 0;
		for (int j = i + 1; j < r; j++){
			ll n = cnd[i], m = cnd[j];
			if (1ll * n * s(m) > 1ll * m * s(n)){
				bad = 1;
				break;
			}
		}
		if (bad == 0)
			return cnd[i];
	}
}

int main(){
	ios_base::sync_with_stdio (false);
	int k;
	cin >> k;
	ll now = 0;
	while (k){
		now = f(now + 1);
		cout << now << '\n';
		k --;
	}
}
