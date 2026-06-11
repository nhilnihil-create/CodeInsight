#include <cmath>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;


int main() {
	int n, m;
	cin >> n >> m;
	ll ans = (1900 * m + 100 * (n - m)) * pow(2, m);
	cout << ans << endl;
	return 0;
}