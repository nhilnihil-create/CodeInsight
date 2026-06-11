#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = s; i < (int)(n); i++)
#define all(obj) obj.begin(), obj.end()
#define db(x) cerr << #x << ":" << x << " "
#define dbl(x) cerr << #x << ":" << x << "\n"
#define dbv(vec) cerr << #vec << ":"; for (auto e : vec) cerr << e << " "; cout << "\n"
#define dbgvv(vv) cerr << #vv << ":\n"; for (auto vec : vv) { for (auto e : vec) cerr << e << " "; cerr << endl; }
#define YN(f) cout << (f ? "YES" : "NO") << endl
#define Yn(f) cout << (f ? "Yes" : "No") << endl
#define yn(f) cout << (f ? "yes" : "no") << endl
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

int main() {
	int N; cin >> N;
	if (N % 2 == 0) {
		int M = N * (N - 2) / 2;
		cout << M << endl;
		rep2(i, 1, N) {
			int gi = min(i, N + 1 - i);
			rep2(j, i + 1, N + 1) {
				int gj = min(j, N + 1 - j);
				db(gi); db(gj); dbl(int(gi != gj));
				if (gi != gj) {
					cout << i << " " << j << endl;
				}
			}
		}
	} else {
		int M = (N - 1) * (N - 1) / 2;
		cout << M << endl;
		rep2(i, 1, N) {
			int gi = min(i, N - i);
			rep2(j, i + 1, N + 1) {
				int gj = (j == N ? N : min(j, N - j));
				db(gi); db(gj); dbl(int(gi != gj));
			 if (gi != gj) {
				 cout << i << " " << j << endl;
			 }
		 }
	 }
 }
}