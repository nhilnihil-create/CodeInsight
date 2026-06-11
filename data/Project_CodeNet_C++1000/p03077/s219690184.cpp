#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n, a, b, c, d, e;
	cin >> n;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	cin >> e;
	ll ans = 4 + ceil((double)n / min(a, min(b, min(c, min(d, e)))));
	cout << ans << endl;
}