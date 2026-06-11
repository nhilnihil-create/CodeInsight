#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

ll s[100010], t[100010];
int main()
{
	int A, B, Q;
	cin >> A >> B >> Q;
	for (int i = 1; i <= A; i++) cin >> s[i];
	for (int i = 1; i <= B; i++) cin >> t[i];
	s[0] = -INF; s[A + 1] = INF;
	t[0] = -INF; t[B + 1] = INF;
	while (Q--) {
		ll x; cin >> x;
		int ok1 = 0;
		int ng1 = A + 2;
		while (abs(ok1 - ng1) > 1) {
			int mid = (ok1 + ng1) / 2;
			if (s[mid] < x) ok1 = mid;
			else ng1 = mid;
		}
		int ok2 = 0;
		int ng2 = B + 2;
		while (abs(ok2 - ng2) > 1) {
			int mid = (ok2 + ng2) / 2;
			if (t[mid] < x) ok2 = mid;
			else ng2 = mid;
		}
		ll ans = INF;
		ans = min(ans, abs(x - s[ok1]) + abs(s[ok1] - t[ok2]));
		ans = min(ans, abs(x - s[ok1]) + abs(s[ok1] - t[ok2 + 1]));
		ans = min(ans, abs(x - s[ok1 + 1]) + abs(s[ok1 + 1] - t[ok2 + 1]));
		ans = min(ans, abs(x - s[ok1 + 1]) + abs(s[ok1 + 1] - t[ok2]));
		ans = min(ans, abs(x - t[ok2]) + abs(t[ok2] - s[ok1]));
		ans = min(ans, abs(x - t[ok2]) + abs(t[ok2] - s[ok1 + 1]));
		ans = min(ans, abs(x - t[ok2 + 1]) + abs(t[ok2 + 1] - s[ok1]));
		ans = min(ans, abs(x - t[ok2 + 1]) + abs(t[ok2 + 1] - s[ok1 + 1]));
		cout << ans << endl;
	}
}
