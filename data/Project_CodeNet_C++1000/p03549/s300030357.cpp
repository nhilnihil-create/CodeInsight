#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
char mine[55][55];
int main() {
	int n, m;
	cin >> n >> m;
	ll ans;
	ans = ((n - m) * 100 + m * 1900) * pow(2, m);
	cout << ans << endl;
	return 0;
}

