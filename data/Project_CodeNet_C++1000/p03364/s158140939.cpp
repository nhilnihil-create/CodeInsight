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

int N;

bool issym(vector<vector<char>> T, int k) {
	rep(i, N) rep2(j, i, N) if (T.at(i).at(k + j) != T.at(j).at(k + i)) return false;
	return true;
}

int main() {
	cin >> N;
	vector<vector<char>> S(N, vector<char>(N));
	rep(i, N) rep(j, N) cin >> S.at(i).at(j);
	dbvv(S);
	rep(i, N) {
		rep(j, N - 1) S.at(i).push_back(S.at(i).at(j));
	}
	dbvv(S);
	int ans = 0;
	rep(k, N) if (issym(S, k)) ans += N;
	cout << ans << endl;
}