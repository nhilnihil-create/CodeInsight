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
class UnionFind {
public:
	vector<int> Parent;

	UnionFind(int N) {
		Parent = vector<int>(N, -1);
	}

	int root(int A) {
		if (Parent[A] < 0) return A;
		return Parent[A] = root(Parent[A]);
	}

	int size(int A) {
		return -Parent[root(A)];
	}

	bool connect(int A, int B) {
		A = root(A);
		B = root(B);
		if (A == B) {
			return false;
		}
		if (size(A) < size(B)) swap(A, B);

		Parent[A] += Parent[B];
		Parent[B] = A;

		return true;
	}
};
void solve() {
	int N, M;
	cin >> N >> M;
	vector<int> A(M), B(M);
	for (int i = 0; i < M; ++i) {
		cin >> A[i] >> B[i];
		A[i]--;
		B[i]--;
	}
	vector<int64> ans(M);
	ans[M - 1] = (int64)N * (N - 1) / 2;

	UnionFind Uni(N);
	
	for (int i = M - 1; i >= 1; --i) {
		ans[i - 1] = ans[i];

		if (Uni.root(A[i]) != Uni.root(B[i])) {
			ans[i - 1] -= (int64)Uni.size(A[i]) * Uni.size(B[i]);
			Uni.connect(A[i], B[i]);
		}
	}

	for(int i = 0; i < M; ++i) {
		cout << ans[i] << endl;
	}
	return;
}

int main() {
	solve();
  return 0;
}