#include <cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
int main() {
	ll n, m;
	cin >> n >> m;
	cout << abs(n - 2) * abs(m - 2) << endl;
	return 0;
}