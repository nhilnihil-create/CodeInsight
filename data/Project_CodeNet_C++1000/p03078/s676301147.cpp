#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <numeric>
#include <string.h>
#define rep(i, x) for (int i = 0; i < (int)(x); i++)
#define repn(i, x) for (int i = 1; i <= (int)(x); i++)
#define repr(i, x) for (int i = ((int)(x) - 1); i >= 0; i--)
#define reprn(i, x) for (int i = ((int)(x)); i > 0; i--)
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long int64;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const int INF = 1<<29;
const long long  INFL = 1e18;
const int MOD = 1000000007;
void solve() {
	int64 X, Y, Z, K; cin >> X >> Y >> Z >> K;
	vector<int64> A(X);
	vector<int64> B(Y);
	vector<int64> C(Z);
	rep (i, X) cin >> A[i];
	rep (i, Y) cin >> B[i];
	rep (i, Z) cin >> C[i];
	sort(all(A)); reverse(all(A));
	sort(all(B)); reverse(all(B));
	sort(all(C)); reverse(all(C));
	vector<int64> ans;
	rep (a, X) {
		rep (b, Y) {
			if ((a + 1) * (b * 1) > K) break;
			rep (c, Z) {
				if ((a + 1) * (b + 1) * (c + 1) > K) break;
				ans.push_back(A[a] + B[b] + C[c]);
			}
		}
	}
	sort(all(ans)); reverse(all(ans));
	rep (i, K) {
		cout << ans[i] << endl;
	}
	return;
}

int main() {
	solve();
  return 0;
}