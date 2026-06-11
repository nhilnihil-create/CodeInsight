#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <map>
const int MOD = 1e9+7;
#define PI 3.14159265359
typedef long long ll;
using namespace std;

ll n, m;
vector<ll> x, y, z;


ll llmax(ll x, ll y){
	if (x > y) return x;
	return y;
}

ll get_max(ll xsign, ll ysign, ll zsign){
	vector<ll> sum(n);
	for (int i = 0; i < n; i++){
		sum[i] = xsign*x[i] + ysign*y[i] + zsign*z[i];
	}
	sort(sum.begin(), sum.end(), greater<ll>());
	ll ans = 0;
	for (int i = 0; i < m; i++){
		ans += sum[i];
	}
	return ans;
}


int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		ll p, q, r;
		cin >> p >> q >> r;
		x.push_back(p);
		y.push_back(q);
		z.push_back(r);
	}
	ll a = get_max(-1, -1, -1);
	ll b = get_max(-1, -1, 1);
	ll c = get_max(-1, 1, -1);
	ll d = get_max(-1, 1, 1);
	ll e = get_max(1, -1, -1);
	ll f = get_max(1, -1, 1);
	ll g = get_max(1, 1, -1);
	ll h = get_max(1, 1, 1);

	ll k = llmax(llmax(a, b), llmax(c, d));
	ll l = llmax(llmax(e, f), llmax(g, h));
	cout << llmax(k, l) << endl;
	return 0;
}