#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = s; i < (int)(n); i++)
#define rep3(i, s, n) for (int i = s; i > (int)(n); i--)
#define all(obj) obj.begin(), obj.end()
#define db(x) cerr << #x << ":" << x << " "
#define dbl(x) cerr << #x << ":" << x << "\n"
#define dbv(vec) cerr << #vec << ":"; for (auto e : vec) cerr << e << " "; cout << "\n"
#define dbvv(vv) cerr << #vv << ":\n"; for (auto vec : vv) { for (auto e : vec) cerr << e << " "; cerr << endl; }
#define YN(f) cout << (f ? "YES" : "NO") << endl
#define Yn(f) cout << (f ? "Yes" : "No") << endl
#define yn(f) cout << (f ? "yes" : "no") << endl
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;


int main() {
	ll K; cin >> K;
	vector<long long> A(K); rep(i, K) cin >> A.at(i);
	vector<long long> min_n(K + 1), max_n(K + 1);
	min_n[K] = max_n[K] = 2;
	dbv(min_n);dbv(max_n);
	bool f = true;
	for (int i = K; i > 0; i--) {
		min_n[i - 1] = (min_n[i] + (A[i - 1] - 1)) / A[i - 1] * A[i - 1];
		max_n[i - 1] = (max_n[i]) / A[i - 1] * A[i - 1] + (A[i - 1] - 1);
		db(i); db(min_n[i-1]); dbl(max_n[i-1]);
		if (min_n[i - 1] > max_n[i - 1]) f = false;
	}
	if (f) {
		cout << min_n[0] << " " << max_n[0] << endl;
	} else {
		cout << -1 << endl;
	}
}