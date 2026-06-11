#include "bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;
const int INF = 1 << 30;
const long long LINF = 1LL << 60;
const long long MOD = 1000000000 + 7;
const double PI = acos(-1);

int main() {
	int N, M; cin >> N >> M;

	int num1 = 1;
	rep(i, M)num1 *= 2;
	int count = 1;
	long long ans = ((N - M) * 100 + 1900 * M) * num1;
	cout << ans;
}
