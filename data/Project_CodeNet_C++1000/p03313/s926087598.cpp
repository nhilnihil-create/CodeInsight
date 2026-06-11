// IOI 2021
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ends ' '
#define die(x) return cout << x << endl, 0
#define all(v) v.begin(), v.end()
#define sz(x) (int)(x.size())
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cerr << ends << H; debug_out(T...); }
#define debug(...) cerr << "{" << #__VA_ARGS__ << "}:", debug_out(__VA_ARGS__)
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const ll MOD = 998244353;
 
////////////////////////////////////////////////////////////////////

const int N = 18 + 1;

pii DP[1 << N];

void Add(pii &a, int x) {
	if (a.first < x) a.second = a.first, a.first = x;
	else if (a.second < x) a.second = x;
}
pii Sync(pii a, pii b) {
	Add(a, b.first), Add(a, b.second);
	return a;
}

int main() {

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	mt19937 Rnd(time(0));
	
	int n; cin >> n;
	for (int i = 0; i < (1 << n); i++) {
		int x; cin >> x;
		DP[i] = make_pair(x, 0);
	}
	for (int i = 0; i < n; i++) for (int mask = (1 << n) - 1; mask >= 0; mask--) {
		if ((mask >> i) & 1) DP[mask] = Sync(DP[mask], DP[mask ^ (1 << i)]);
	}
	int ans = 0;
	for (int i = 1; i < (1 << n); i++) {
		ans = max(ans, DP[i].first + DP[i].second);
		cout << ans << endl;
	}
	
	return 0;
}
