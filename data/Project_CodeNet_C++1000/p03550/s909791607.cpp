#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, z, w, ans;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> z >> w;
	vi a(n);
	for (auto& i : a) cin >> i;
	ans = abs(w - a[n - 1]);
	if (n > 1) ans = max(ans, abs(a[n - 2] - a[n - 1]));
	cout << ans;
}
