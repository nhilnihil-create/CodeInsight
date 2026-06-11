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
	ll ans = 0; int d;
	rep(i, N - 1) {
		d = A.at(i + 1) - A.at(i);
		if (d > 1) { ans = -1; break;	}
		else if (d == 1) ans++;
		else if (d < 1) ans+= A.at(i + 1);
	}
	if (A.at(0) > 0) ans = -1;
	cout << ans << endl;
}