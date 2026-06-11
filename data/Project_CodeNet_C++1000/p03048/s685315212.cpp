#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int r, g, b, n;
	cin >> r >> g >> b >> n;
	int ans = 0;
	for (int i = 0; i <= 3000; ++i) {
		for (int j = 0; j <= 3000; ++j) {
			if (i * r + j * g > n) continue;
			if ((n - (i * r + j * g)) % b == 0) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
