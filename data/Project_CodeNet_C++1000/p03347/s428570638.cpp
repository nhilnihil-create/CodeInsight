#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = s; i < (int)n; i++)
#define all(obj) obj.begin(), obj.end()
#define debug(x) cerr << #x << ":" << x << "\n"
#define vdebug(vec) cerr << #vec << ":"; for (auto e : vec) cerr << e << " "; cout << "\n"
#define YN(f) cout << (f ? "YES" : "NO") << endl
#define Yn(f) cout << (f ? "Yes" : "No") << endl
#define yn(f) cout << (f ? "yes" : "no") << endl
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

int main () {
	int N; cin >> N;
	vi A(N); rep(i, N) cin >> A.at(i);
	int h = 0; ll ans = 0;
	for (int i = N - 1; i >= 0; i--) {
		h--;
		if (h < A.at(i)) {
			h = A.at(i);
			ans += h;			
		} else if (h > A.at(i)) {
			ans = -1;
			break;
		}
	}
	if (A.at(0) > 0) ans = -1;
	cout << ans << endl;
}