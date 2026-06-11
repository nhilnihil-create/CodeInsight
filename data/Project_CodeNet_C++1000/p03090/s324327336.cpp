#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i, n) for (int i = 0, i##_len = (int)(n); i < i##_len; i++)
#define reps(i, n) for (int i = 1, i##_len = (int)(n); i <= i##_len; i++)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define rreps(i, n) for (int i = ((int)(n)); i > 0; i--)
#define repi(i, x) \
	for (auto i = (x).begin(), i##_fin = (x).end(); i != i##_fin; i++)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define solve(a) ((a) ? "Yes" : "No")
typedef vector<int> Vi;
typedef vector<Vi> VVi;
typedef pair<int, int> Pi;
typedef vector<Pi> VPi;
typedef vector<long long> V;
typedef vector<V> VV;
typedef pair<long long, long long> P;
typedef vector<P> VP;
template <class T>
inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return 1;
	}
	return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return 1;
	}
	return 0;
}
const long long INFLL = 1LL << 60;
const int INF         = 1 << 30;
const double PI       = acos(-1);
int main() {
	int n;
	int ans = 0;
	cin >> n;
	int sum = (n % 2 == 0) ? n + 1 : n;

	vector<pair<int, int>> path;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (sum - i != j) {
				path.push_back(mp(i, j));
			}
		}
	}

	cout << path.size() << endl;
	repi(itr, path) { printf("%d %d\n", itr->F, itr->S); }
}
/*
1=2 3 (1 4)
2=1 4 (2 3)
3=1 4 (2 3)
4=2 3 (1 4)

1=2 (3)
2=1 (3)
3=1 2

1=2 3 5(1 4)=10
2=1 4 5(2 3)=10
3=1 4 5(3 2)=10
4=2 3 5(4 1)=10
5=1 2 3 4=10
15 *2 = 30 (6)
*/