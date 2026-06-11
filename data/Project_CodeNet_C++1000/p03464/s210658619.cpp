#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = s; i < (int)n; i++)
#define rep3(i, s, n) for (int i = s; i > (int)n; i--)
#define all(obj) obj.begin(), obj.end()
#define db(x) cerr << #x << ":" << x << " "
#define dbl(x) cerr << #x << ":" << x << "\n"
#define dbv(vec) cerr << #vec << ":"; for (auto e : vec) cerr << e << " "; cout << "\n"
#define YN(f) cout << (f ? "YES" : "NO") << endl
#define Yn(f) cout << (f ? "Yes" : "No") << endl
#define yn(f) cout << (f ? "yes" : "no") << endl
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

int main () {
	int K; cin >> K;
	vi A(K); rep(i, K) cin >> A.at(i);
	ll m = 2, M = 2;
	rep3(i, K - 1, -1) {
		int Ai = A.at(i);
		m = ((m + Ai - 1) / Ai) * Ai;
		M = (M / Ai) * Ai;
		M += Ai - 1;
	}
	if (m > M) {
		cout << -1 << endl;
	} else {
		cout << m << " " << M << endl;
	}	
}