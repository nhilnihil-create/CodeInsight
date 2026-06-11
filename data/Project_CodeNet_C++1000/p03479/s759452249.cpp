#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
 
int main() {
	ll x, y;
	cin >> x >> y;
	ll a = x;
	int ans = 1;
	while (a*2 <= y)
	{
		a *= 2;
		ans++;
	}
	
	cout << ans << endl;
	return 0;
}