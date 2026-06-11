#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
 
int main() {
	ll n;
	cin >> n;
	for (int a = 1; a <= 3500; a++)
	{
		for (int b = 1; b <= 3500; b++)
		{
			ll up = n*a*b;
			ll down = 4*a*b-n*a-n*b;
			if (down <= 0) continue;
			if (up % down == 0) {
				ll c = up / down;
				cout << a << ' ' << b << ' '<< c << endl;
				return 0;
			}
		}
		
	}
	
	return 0;
}