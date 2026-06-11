#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(int argc, char **argv) {
	ll x;
	ll y;
	cin >> x >> y;
	ll ans = x % y == 0 ? -1 : x;
	cout << ans << endl;
}
