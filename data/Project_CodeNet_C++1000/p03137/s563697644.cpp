#include <cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
ll x[100005];
int main() {
	ll n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x[i];
	}
	sort(x, x + m);
	
	ll dif[100005];
	for (int i = 0; i < m-1; i++) {
		dif[i] = x[i + 1] - x[i];
	}
	sort(dif, dif +( m - 1));
	ll sum = 0;
	
	for (int i = 0; i < m - (n - 1)-1; i++) {
		
		sum += dif[i];
	}
	cout << sum << endl;
	return 0;
}

