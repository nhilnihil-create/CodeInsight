#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 29;
 
int main() {
	ll n;
	cin >> n;
	bool all9 = true;
	int cnt = 0;
	while (n >= 10)
	{
		if (n % 10 != 9) all9 = false;
		n /= 10;
		cnt++;
	}
	int ans = n + cnt * 9;
	if (all9) cout << ans << endl;
	else cout << ans -1 << endl;
}
