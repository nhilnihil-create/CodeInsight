#include <cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
int main() {
	ll n, a, b, c, d, e;
	cin >> n >> a >> b >> c >> d >> e;
	ll check = min({ a,b,c,d,e });
	if (n % check != 0) {
		cout << (n / check) + 5 << endl;
	}
	else
	cout << (n / check) + 4 << endl;
	return 0;
}

