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

const int N = 1e3 + 5, M = 1e4 + 5;

ll DP[N * M];
int W[N], S[N], V[N], P[N];

int CMP(int i, int j) { return W[i] + S[i] < W[j] + S[j]; }

int main() {

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> W[i] >> S[i] >> V[i], P[i] = i;
	sort(P, P + n, CMP);
	for (int i = 0; i < n; i++) {
		for (int j = S[P[i]]; j >= 0; j--) {
			DP[j + W[P[i]]] = max(DP[j + W[P[i]]], DP[j] + V[P[i]]);
		}
	}
	cout << *max_element(DP, DP + N * M) << endl;

	return 0;
}
