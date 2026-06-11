#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()


int main() {
#ifdef local
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int ans = n * 2;
	if(n % 2 == 0) ans /= 2;
	cout << ans << '\n';
	return 0;
}
