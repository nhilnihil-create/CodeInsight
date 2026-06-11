#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
 
int main() {
	int n;
	string s;
	cin >> n >> s;
	int b = 0, w = 0;
	rep(i,n) {
		if (s[i] == '.') w++; 
	}
	int ans = w;

	rep(i,n) {
		if (s[i] == '#') b++;
		else w--;
		ans = min(ans, b+w);
	}
	cout << ans << endl;
	return 0;
}