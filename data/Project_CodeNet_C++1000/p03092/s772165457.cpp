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
const ll MOD = 1e9 + 7;
 
////////////////////////////////////////////////////////////////////

const int N = 5e3 + 5;

int P[N], C[N][N], M[N][N];
ll DP[N][N];
// C[i][j] : # k : i <= k <= j && A[i] > A[k] 
// M[i][j] : index maximum A[k] <= j && k <= i
// DP[i][j] : answer for first i element and numbers less than j
int main() {

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	mt19937 Rnd(time(0));

	int n, A, B; cin >> n >> A >> B;
	for (int i = 1; i <= n; i++) cin >> P[i];
	for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) C[i][j] = C[i][j - 1] + (P[i] > P[j]);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) M[i][j] = (P[i] <= j && P[i] > P[M[i - 1][j]]) ?  i : M[i - 1][j];
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
		if (!M[i][j]) continue;
		DP[i][j] = min(A + DP[i][P[M[i][j]] - 1], DP[M[i][j] - 1][j] + 1LL * C[M[i][j]][i] * B);
	}
	cout << DP[n][n] << endl;

	return 0;
}
