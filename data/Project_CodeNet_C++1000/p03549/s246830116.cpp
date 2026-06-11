#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n, m; cin >> n >> m;

	int ans = 0;
	int tmp = pow(2, m);

	ans += m * 1900 * tmp + (n - m) * 100 * tmp;

	cout << ans << endl;
    return 0;
}