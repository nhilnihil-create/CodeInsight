#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i, a, b) for(int i = (int)a; i <= (int)b; i++)

vector<int> v;
int n, a, b, ans;
bool same = true;

int32_t main() {
	cin >> n;
	FOR(i, 1, n) {
		cin >> a >> b;
		ans += b;
		if (a != b) same = false;
		if (a > b) v.push_back(b);
	}
	if (same) cout << 0;
	else if (v.empty()) cout << ans;
	else cout << ans - (*min_element(v.begin(), v.end()));
}
