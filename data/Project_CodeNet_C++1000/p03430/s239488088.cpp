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
const ll INF = 1e9;
const ll MOD = 1e9 + 7;

////////////////////////////////////////////////////////////////////

const int N = 3e2 + 2;

int DP[N][N][N];

int main() {

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);	

	string s; cin >> s;
	int n = sz(s), k; cin >> k;
	for (int l = n; l >= 1; l--) for (int r = l; r <= n; r++) for (int i = 0; i <= k; i++) {
		if (l == r) DP[l][r][i] = 1;
		else DP[l][r][i] = max(max(DP[l + 1][r][i], DP[l][r - 1][i]), max((i > 0) * (DP[l + 1][r - 1][i - 1] + 2), (s[l - 1] == s[r - 1]) * (DP[l + 1][r - 1][i] + 2)));
	}
	cout << DP[1][n][k] << endl;

	return 0;
}
